#include "Lexer.hh"
#include <map>
#include <vector>
#include <algorithm>
#include <regex>

#define CBETWEEN(val, min, max) (val >= min && val <= max)

// Remove me!
#include <iostream>

kyu::lang::Lexer::Lexer()
{
    SetSource("");
}

void kyu::lang::Lexer::SetSource(std::string source)
{
    m_source = source;

    m_index = 0;
    m_line = 0;
    m_column = 0;
}

std::vector<char> _whitespace_chars = {' ', '\n', '\r', '\t'};

std::map<char, kyu::lang::Token> _single_char_tokens =
{
    {'(', kyu::lang::Token(kyu::lang::TokenType::ExpressionOpen, "(")},
    {')', kyu::lang::Token(kyu::lang::TokenType::ExpressionClose, ")")}
};

char kyu::lang::Lexer::GetNextChar()
{
    // Emit a null character if the source doesn't contain more characters
    if (m_index >= m_source.length()) return '\0';

    char character = m_source[m_index++];

    if (character == '\n')
    {
        m_line++;
        m_column = 0;
    }

    return character;
}

char kyu::lang::Lexer::PeekNextChar()
{
    
    // Emit a null character if the source doesn't contain more characters
    if (m_index >= m_source.length()) return '\0';

    return m_source[m_index];
}

kyu::lang::Token kyu::lang::Lexer::GetNextToken()
{
    char current_char = GetNextChar();

    // Skip all whitespace characters
    while (std::count(_whitespace_chars.begin(), _whitespace_chars.end(), current_char) && current_char != '\0')
    {
        current_char = GetNextChar();
    }

    // Emit an EOF token if there is no more text to tokenize
    if (current_char == '\0') return Token(TokenType::EndOfFile, "");

    // Check for single character tokens
    if (_single_char_tokens.find(current_char) != _single_char_tokens.end())
    {
        return _single_char_tokens[current_char];
    }

    // Check for numbers (currently only decimal numbers)
    if (std::isdigit(current_char))
    {
        std::string number(1, current_char);

        while (std::isdigit(PeekNextChar()))
        {
            number += GetNextChar();
        }

        return Token(TokenType::Number, number);
    }

    // Check for strings
    if (current_char == '"')
    {
        current_char = GetNextChar();
        std::string text = "";

        while (current_char != '"')
        {
            text += current_char;
            current_char = GetNextChar();
        }

        return Token(TokenType::String, text);
    }

    // Check for symbols
    if (CBETWEEN(current_char, 'a', 'z') || CBETWEEN(current_char, 'A', 'Z') || current_char == '+' || current_char == '-')
    {
        std::string symbol(1, current_char);
        char next_char = PeekNextChar();

        while (CBETWEEN(next_char, 'a', 'z') || CBETWEEN(next_char, 'A', 'Z') || CBETWEEN(next_char, '0', '9') || next_char == '-' || next_char == '_')
        {
            symbol += GetNextChar();
            next_char = PeekNextChar();
        }

        return Token(TokenType::Symbol, symbol);
    }

    // If we get here we were not able to parse the token
    return Token(TokenType::Invalid, "");
}

bool kyu::lang::Lexer::HasNextToken()
{
    return m_index < m_source.length();
}