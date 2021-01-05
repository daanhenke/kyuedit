#include "ast/KList.hh"

kyu::lang::ast::KList::KList(std::vector<KValue*> values) : KValue(KValueType::List)
{
    m_values = values;
}

std::string kyu::lang::ast::KList::ToString()
{
    std::string argString = "";

    bool firstParam = true;
    for (auto entry : m_values)
    {
        if (! firstParam)
        {
            argString += " ";
        }
        firstParam = false;

        argString += entry->ToString();
    }

    return "(" + argString + ")";
}

size_t kyu::lang::ast::KList::ValueCount()
{
    return m_values.size();
}

std::vector<kyu::lang::ast::KValue*> kyu::lang::ast::KList::GetValues()
{
    return m_values;
}

kyu::lang::ast::KValue* kyu::lang::ast::KList::GetValue(size_t index)
{
    return m_values[index];
}