#pragma once
#include "ast/KValue.hh"
#include <string>

namespace kyu::lang::ast
{
    class KString : public KValue
    {
    protected:
        std::string m_value;

    public:
        explicit KString(std::string value);
        
        std::string ToString() override;
        std::string GetValue();
    };
}