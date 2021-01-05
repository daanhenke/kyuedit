#pragma once
#include "ast/KValue.hh"
#include <vector>

namespace kyu::lang::ast
{
    class KSubroutine : public KValue
    {
    protected:
        std::vector<std::string> m_params;
        KValue* m_expression;

    public:
        KSubroutine(std::vector<std::string> params, KValue* expression);

        KValue* GetExpression();
        std::vector<std::string> GetParameterNames();
        std::string ToString();
    };
}