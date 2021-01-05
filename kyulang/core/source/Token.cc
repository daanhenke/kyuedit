#include "Token.hh"

kyu::lang::Token::Token(TokenType type, std::string value) : m_type(type), m_value(value) {}

kyu::lang::TokenType kyu::lang::Token::GetType()
{
    return m_type;
}

std::string kyu::lang::Token::GetValue()
{
    return m_value;
}