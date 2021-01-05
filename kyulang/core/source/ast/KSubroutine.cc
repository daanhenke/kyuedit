#include "ast/KSubroutine.hh"
#include <sstream>

kyu::lang::ast::KSubroutine::KSubroutine(std::vector<std::string> params, KValue *expression) : KValue(KValueType::Subroutine), m_params(params), m_expression(expression) {}

kyu::lang::ast::KValue* kyu::lang::ast::KSubroutine::GetExpression()
{
    return m_expression;
}

std::vector<std::string> kyu::lang::ast::KSubroutine::GetParameterNames()
{
    return m_params;
}

std::string kyu::lang::ast::KSubroutine::ToString()
{
    std::stringstream stream;
    stream << "Subroutine<";

    bool first = true;
    for (auto param : m_params)
    {
        if (! first) stream << ", ";
        first = false;
        stream << param;
    }

    stream << ">";
    return stream.str();
}