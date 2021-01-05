#pragma once
#include <string>

namespace kyu::lang
{
    typedef enum TokenType
    {
        EndOfFile,
        ExpressionOpen,
        ExpressionClose,
        Number,
        String,
        Symbol,
        Invalid
    } TokenType;

    class Token
    {
    protected:
        TokenType m_type;
        std::string m_value;

    public:
        Token(TokenType type = TokenType::Invalid, std::string value = "");

        TokenType GetType();
        std::string GetValue();
    };
}