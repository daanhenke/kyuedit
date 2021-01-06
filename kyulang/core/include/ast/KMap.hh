#pragma once
#include "ast/KValue.hh"
#include <map>
#include <vector>

namespace kyu::lang::ast
{
    class KMap : public KValue
    {
    protected:
        std::map<std::string, KValue*> m_inner;

    public:
        KMap();

        void Set(std::string key, KValue* value);
        KValue* Get(std::string key);
        std::vector<std::string> GetKeys();

        std::string ToString() override;
    };
}