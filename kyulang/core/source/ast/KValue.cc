#include "ast/KValue.hh"

kyu::lang::ast::KValue::KValue(KValueType type) : m_type(type) {}

kyu::lang::ast::KValueType kyu::lang::ast::KValue::GetType()
{
    return m_type;
}