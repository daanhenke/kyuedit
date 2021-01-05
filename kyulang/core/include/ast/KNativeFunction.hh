#pragma once
#include "ast/KValue.hh"
#include <vector>

namespace kyu::lang
{
    class VirtualMachine;
}

namespace kyu::lang::ast
{
    typedef std::vector<KValue*> ValueVector;
    typedef KValue* (*KNativeFunctionCallback)(VirtualMachine* vm, const ValueVector& arguments);

    class KNativeFunction : public KValue
    {
    protected:
        std::string m_name;
        KNativeFunctionCallback m_callback;

    public:
        KNativeFunction(std::string name, KNativeFunctionCallback callback);

        std::string ToString();
        std::string GetName();
        KNativeFunctionCallback GetCallback();
    };
}