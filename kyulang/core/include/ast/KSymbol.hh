#pragma once
#include "ast/KValue.hh"
#include <string>

namespace kyu::lang::ast
{
    class KSymbol : public KValue
    {
    protected:
        std::string m_name;

    public:
        explicit KSymbol(std::string name);

        std::string ToString() override;
        std::string GetName();
    };
}