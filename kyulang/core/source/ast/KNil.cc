#include "ast/KNil.hh"

kyu::lang::ast::KNil::KNil() : KValue(KValueType::Nil) {}

std::string kyu::lang::ast::KNil::ToString()
{
    return "nil";
}