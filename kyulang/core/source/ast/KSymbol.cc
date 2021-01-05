#include "ast/KSymbol.hh"

kyu::lang::ast::KSymbol::KSymbol(std::string name) : KValue(KValueType::Symbol)
{
    m_name = name;
}

std::string kyu::lang::ast::KSymbol::ToString()
{
    return "Symbol<" + m_name + ">";
}

std::string kyu::lang::ast::KSymbol::GetName()
{
    return m_name;
}