#include "logic.hh"
#include <iostream>

DEFINE_STDFUNC(kyu::lang::stdlib::logic::_if)
{
    if (args.size() < 2 || args.size() > 3)
    {
        // TODO: THROW ERROR HERE
        return new ast::KNil();
    }

    // Evaluate the expression so we can test it's results
    auto result = reinterpret_cast<ast::KNumber*>(vm->EvaluateValue(args[0]));

    if (result->GetType() != ast::KValueType::Number)
    {
        // TODO: CONVERT TO NUMBER
        return new ast::KNil();
    }

    bool success = result->GetValue() != 0;

    if (success) {
        // Evaluate the true expression
        return vm->EvaluateValue(args[1]);
    }

    if (args.size() == 3)
    {
        // Evaluate the false expression
        return vm->EvaluateValue(args[2]);
    }

    // No false expression, so just return false
    return new ast::KFalse();
}

DEFINE_STDFUNC(kyu::lang::stdlib::logic::equal)
{
    if (args.size() != 2)
    {
        // THROW ERROR HERE
        return new ast::KFalse();
    }

    auto first = vm->EvaluateValue(args[0]);
    auto second = vm->EvaluateValue(args[1]);

    // Different types, so not equal
    if (first->GetType() != second->GetType())
    {
        return new ast::KFalse();
    }

    bool success = false;
    switch (first->GetType()) {

        case ast::Number:
            success = reinterpret_cast<ast::KNumber*>(first)->GetValue() == reinterpret_cast<ast::KNumber*>(second)->GetValue();
            break;

        case ast::String:
            success = reinterpret_cast<ast::KString*>(first)->GetValue() == reinterpret_cast<ast::KString*>(second)->GetValue();
            break;
        case ast::List:
            // TODO: IMPLEMENT
            break;
        case ast::Nil:
            // Both values will be nil here
            success = true;
            break;
        case ast::NativeFunction:
            success = reinterpret_cast<ast::KNativeFunction*>(first)->GetName() == reinterpret_cast<ast::KNativeFunction*>(second)->GetName();
            break;
    }

    if (success) {
        return new ast::KTrue();
    }

    return new ast::KFalse();
}

DEFINE_STDFUNC(kyu::lang::stdlib::logic::subroutine)
{
    if (args.size() != 2)
    {
        return new ast::KNil();
    }

    auto param_list = reinterpret_cast<ast::KList*>(args[0]);
    if (param_list->GetType() != ast::KValueType::List)
    {
        return new ast::KNil();
    }

    std::vector<std::string> params;
    for (auto value : param_list->GetValues())
    {
        if (value->GetType() != ast::KValueType::Symbol)
        {
            return new ast::KNil();
        }

        params.emplace_back(reinterpret_cast<ast::KSymbol*>(value)->GetName());
    }

    auto expression = reinterpret_cast<ast::KList*>(args[1]);
    return new ast::KSubroutine(params, expression);
}

DEFINE_STDFUNC(kyu::lang::stdlib::logic::local)
{
    auto key = reinterpret_cast<ast::KSymbol*>(args[0]);

    if (key->GetType() != ast::KValueType::Symbol)
    {
        return new ast::KNil();
    }

    auto value = vm->EvaluateValue(args[1]);
    vm->UpdateSymbol(key, value);

    return value;
}

DEFINE_STDFUNC(kyu::lang::stdlib::logic::global)
{
    auto key = reinterpret_cast<ast::KSymbol*>(args[0]);

    if (key->GetType() != ast::KValueType::Symbol)
    {
        return new ast::KNil();
    }

    auto value = vm->EvaluateValue(args[1]);
    // TODO: GLOBALS CAN OVERWRITE BUILTINS NOW
    vm->GetGlobalFrame()->SetValue(key->GetName(), value);

    return value;
}