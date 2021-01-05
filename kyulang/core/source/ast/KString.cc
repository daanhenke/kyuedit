#include "ast/KString.hh"

kyu::lang::ast::KString::KString(std::string value) : KValue(KValueType::String)
{
    m_value = value;
}

std::string kyu::lang::ast::KString::ToString()
{
    return "\"" + m_value + "\"";
}

std::string kyu::lang::ast::KString::GetValue()
{
    return m_value;
}