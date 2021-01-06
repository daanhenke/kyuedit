#include "VirtualMachine.hh"
#include <sstream>
#include <iostream>

kyu::lang::VirtualMachine::VirtualMachine()
{
    m_builtins_frame = new Frame();
    m_global_frame = new Frame(m_builtins_frame);
    m_current_frame = m_global_frame;
}

void kyu::lang::VirtualMachine::EvaluateString(std::string source)
{
    std::vector<ast::KValue*> expressions = m_parser.ParseSourceString(source);

    for (ast::KValue* expression : expressions)
    {
        //std::cout << "inp: " << expression->ToString() << std::endl;
        ast::KValue* output = EvaluateValue(expression);
        std::cout << output->ToString() << std::endl;
    }
}

kyu::lang::ast::KValue* kyu::lang::VirtualMachine::EvaluateValue(ast::KValue* input)
{
    ast::KValueType type = input->GetType();

    // Can't evaluate constants...
    if (type == ast::KValueType::Number || type == ast::KValueType::String || type == ast::KValueType::Map)
    {
        return input;
    }

    if (type == ast::KValueType::Symbol)
    {
        auto symbol = reinterpret_cast<ast::KSymbol*>(input);
        return ResolveSymbol(symbol);
    }

    // Lists can be either constants, or function calls
    if (type == ast::KValueType::List)
    {
        auto list = reinterpret_cast<ast::KList*>(input);

        // Don't really need to do anything with empty lists
        if (list->ValueCount() > 0)
        {
            auto first_entry = list->GetValue(0);

            // Check if the first entry in the list is a symbol
            if (first_entry->GetType() == ast::KValueType::Symbol)
            {
                // Get the underlying value of the symbol
                auto symbol = reinterpret_cast<ast::KSymbol*>(first_entry);
                auto value = ResolveSymbol(symbol);

                // Check if the underlying variable is a native function
                if (value->GetType() == ast::KValueType::NativeFunction)
                {
                    // Call the underlying function
                    auto natfunc = reinterpret_cast<ast::KNativeFunction*>(value);
                    auto callback = natfunc->GetCallback();

                    // The callback should resolve to a normal type
                    std::vector<ast::KValue*> arguments;

                    auto rawargs = list->GetValues();
                    if (rawargs.size() > 1)
                    {
                        for (auto iterator = rawargs.begin() + 1; iterator != rawargs.end(); iterator++)
                        {
                            arguments.emplace_back(*iterator);
                        }
                    }


                    return callback(this, arguments);
                }

                // Check if the underlying variable is a subroutine
                if (value->GetType() == ast::KValueType::Subroutine)
                {
                    auto sub = reinterpret_cast<ast::KSubroutine*>(value);
                    auto frame = new Frame(m_current_frame);

                    size_t index = 0;
                    for (const auto& param : sub->GetParameterNames())
                    {
                        frame->SetValue(param, list->ValueCount() > index + 1 ? EvaluateValue(list->GetValue(index + 1)) : new ast::KNil());
                        index++;
                    }

                    m_current_frame = frame;
                    auto result = EvaluateValue(sub->GetExpression());
                    m_current_frame = m_current_frame->GetParent();
                    return result;
                }
            }
        }

        // Default action for lists
        return list;
    }

    // Should never arrive here, but the compiler will throw a warning
    return nullptr;
}

kyu::lang::ast::KValue* kyu::lang::VirtualMachine::ResolveSymbol(ast::KSymbol* symbol)
{
    auto frame = m_current_frame->FindValueHolder(symbol->GetName());
    if (frame != nullptr)
    {
        auto value = frame->GetValue(symbol->GetName());
        if (value != nullptr)
        {
            return value;
        }
    }

    return new ast::KNil();
}

void kyu::lang::VirtualMachine::UpdateSymbol(ast::KSymbol *symbol, ast::KValue *value)
{
    auto frame = m_current_frame->FindValueHolder(symbol->GetName());

    if (frame == nullptr)
    {
        frame = m_current_frame;
    }

    frame->SetValue(symbol->GetName(), value);
}

kyu::lang::Frame* kyu::lang::VirtualMachine::GetBuiltinsFrame()
{
    return m_builtins_frame;
}

kyu::lang::Frame* kyu::lang::VirtualMachine::GetGlobalFrame()
{
    return m_global_frame;
}

kyu::lang::Frame* kyu::lang::VirtualMachine::GetCurrentFrame()
{
    return m_current_frame;
}