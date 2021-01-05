#pragma once
#include <string>
#include "Token.hh"

namespace kyu::lang
{
    class Lexer
    {
    protected:
        std::string m_source;
        unsigned long m_index;
        unsigned long m_line;
        unsigned long m_column;

    public:
        Lexer();

        void SetSource(std::string source);
        char GetNextChar();
        char PeekNextChar();
        Token GetNextToken();
        bool HasNextToken();
    };
}