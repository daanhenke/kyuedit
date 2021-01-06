#include "ast/KMap.hh"
#include <sstream>

kyu::lang::ast::KMap::KMap() : KValue(ast::KValueType::Map) {}

void kyu::lang::ast::KMap::Set(std::string key, KValue* value)
{
    m_inner[key] = value;
}

kyu::lang::ast::KValue* kyu::lang::ast::KMap::Get(std::string key)
{
    if (m_inner.contains(key))
    {
        return m_inner[key];
    }

    return nullptr;
}

std::vector<std::string> kyu::lang::ast::KMap::GetKeys()
{
    std::vector<std::string> keys;

    for (auto& iterator : m_inner)
    {
        keys.emplace_back(iterator.first);
    }

    return keys;
}

std::string kyu::lang::ast::KMap::ToString()
{
    std::stringstream stream;
    stream << "Map<";
    bool first = true;
    for (auto& iterator : m_inner)
    {
        if (! first) stream << ", ";
        first = false;
        stream << iterator.first << ": " << iterator.second->ToString();
    }
    stream << ">";

    return stream.str();
}