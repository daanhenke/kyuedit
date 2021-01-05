#pragma once
#include "ast/KValue.hh"

namespace kyu::lang::ast
{
    class KNil : public KValue
    {
    public:
        KNil();

        std::string ToString();
    };
}