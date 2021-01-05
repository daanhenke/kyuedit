#pragma once
#include "ast/KValue.hh"
#include "ast/KSymbol.hh"
#include <vector>

namespace kyu::lang::ast
{
    class KList : public KValue
    {
    protected:
        std::vector<KValue*> m_values;
    public:
        explicit KList(std::vector<KValue*> values);

        std::string ToString() override;
        size_t ValueCount();
        std::vector<KValue*> GetValues();
        KValue* GetValue(size_t index);
    };
}