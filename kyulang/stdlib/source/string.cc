#include "string.hh"

DEFINE_STDFUNC(kyu::lang::stdlib::string::concat)
{
    std::string out;

    for (auto arg : args)
    {
        auto value = vm->EvaluateValue(arg);

        if (value->GetType() != ast::KValueType::String)
        {
            // TODO: ERROR HERE
        }
        else
        {
            out += reinterpret_cast<ast::KString*>(value)->GetValue();
        }
    }

    return new ast::KString(out);
}