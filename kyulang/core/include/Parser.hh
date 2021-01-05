#pragma once
#include "Lexer.hh"
#include "ast/KValue.hh"
#include "ast/KNumber.hh"
#include "ast/KString.hh"
#include "ast/KSymbol.hh"
#include "ast/KList.hh"

namespace kyu::lang
{
    class Parser
    {
    protected:
        Lexer m_lexer;
        Token m_current_token;

    public:
        void ConsumeToken();
        std::vector<ast::KValue*> ParseSourceString(std::string source);
        ast::KValue* ParseExpression();
        ast::KNumber* ParseNumber();
        ast::KString* ParseString();
        ast::KSymbol* ParseSymbol();
        ast::KList* ParseList();
    };
}