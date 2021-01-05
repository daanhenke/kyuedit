#include "ast/KNumber.hh"

kyu::lang::ast::KNumber::KNumber(double value) : KValue(KValueType::Number)
{
    m_value = value;
}

std::string kyu::lang::ast::KNumber::ToString()
{
    return std::to_string(m_value);
}

double kyu::lang::ast::KNumber::GetValue()
{
    return m_value;
}