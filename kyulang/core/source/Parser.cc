#include "Parser.hh"
#include "ast/KNumber.hh"
#include "ast/KString.hh"
#include "ast/KSymbol.hh"
#include <iostream>
#include <utility>

void kyu::lang::Parser::ConsumeToken()
{
    m_current_token = m_lexer.GetNextToken();
}

std::vector<kyu::lang::ast::KValue*> kyu::lang::Parser::ParseSourceString(std::string source)
{
    m_lexer.SetSource(std::move(source));
    std::vector<ast::KValue*> results;

    ConsumeToken();
    while (m_current_token.GetType() != TokenType::EndOfFile)
    {
        ast::KValue* value = ParseExpression();

        if (value == nullptr)
        {
            break;
        }

        results.emplace_back(value);
    }

    return results;
}

kyu::lang::ast::KValue* kyu::lang::Parser::ParseExpression()
{
    if (m_current_token.GetType() == TokenType::Number)
    {
        return ParseNumber();
    }

    if (m_current_token.GetType() == TokenType::String)
    {
        return ParseString();
    }

    if (m_current_token.GetType() == TokenType::Symbol)
    {
        return ParseSymbol();
    }

    if (m_current_token.GetType() == TokenType::ExpressionOpen)
    {
        return ParseList();
    }

    return nullptr;
}

kyu::lang::ast::KNumber* kyu::lang::Parser::ParseNumber()
{
    if (m_current_token.GetType() != TokenType::Number)
    {
        return nullptr;
    }

    auto val = new ast::KNumber(std::stod(m_current_token.GetValue()));
    ConsumeToken();
    return val;
}

kyu::lang::ast::KString* kyu::lang::Parser::ParseString() {
    if (m_current_token.GetType() != TokenType::String)
    {
        return nullptr;
    }

    auto val = new ast::KString(m_current_token.GetValue());
    ConsumeToken();
    return val;
}

kyu::lang::ast::KSymbol* kyu::lang::Parser::ParseSymbol() {
    if (m_current_token.GetType() != TokenType::Symbol)
    {
        return nullptr;
    }

    auto val = new ast::KSymbol(m_current_token.GetValue());
    ConsumeToken();
    return val;
}

kyu::lang::ast::KList* kyu::lang::Parser::ParseList() {
    if (m_current_token.GetType() != TokenType::ExpressionOpen)
    {
        return nullptr;
    }

    // Consume the first (
    ConsumeToken();

    // Get all of the values inside the list
    std::vector<ast::KValue*> values;
    while (m_current_token.GetType() != TokenType::ExpressionClose)
    {
        values.emplace_back(ParseExpression());
    }

    // Consume the final )
    ConsumeToken();

    return new ast::KList(values);
}