#pragma once
#include "ast/KValue.hh"

namespace kyu::lang::ast
{
    class KNumber : public KValue
    {
    protected:
        double m_value;

    public:
        explicit KNumber(double value);

        std::string ToString() override;
        double GetValue();
    };

    class KTrue : public KNumber
    {
    public:
        KTrue() : KNumber(1) {}
    };

    class KFalse : public KNumber
    {
    public:
        KFalse() : KNumber(0) {}
    };
}