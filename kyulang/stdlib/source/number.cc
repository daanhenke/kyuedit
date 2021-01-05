#include "number.hh"

DEFINE_STDFUNC(kyu::lang::stdlib::number::add)
{
    double result = 0;

    for (auto arg : args)
    {
        auto value = vm->EvaluateValue(arg);
        if (value->GetType() != ast::KValueType::Number)
        {
            // TODO: THROW ERROR HERE
        }

        result += reinterpret_cast<ast::KNumber*>(value)->GetValue();
    }

    return new ast::KNumber(result);
}

DEFINE_STDFUNC(kyu::lang::stdlib::number::subtract)
{
    double result = 0;
    auto value = vm->EvaluateValue(args[0]);

    if (args.size() == 1)
    {
        return new ast::KNumber(-reinterpret_cast<ast::KNumber*>(value)->GetValue());
    }
    else if (!args.empty())
    {
        result = reinterpret_cast<ast::KNumber*>(value)->GetValue();

        for (size_t i = 1; i < args.size(); i++)
        {
            result -= reinterpret_cast<ast::KNumber*>(vm->EvaluateValue(args[i]))->GetValue();
        }
    }

    return new ast::KNumber(result);
}