#include "Frame.hh"

kyu::lang::Frame::Frame(Frame* parent, bool readOnly) : m_parent(parent), m_readonly(readOnly) {}

kyu::lang::ast::KValue* kyu::lang::Frame::GetValue(std::string key)
{
    return m_vars.contains(key) ? m_vars[key] : nullptr;
}

void kyu::lang::Frame::SetValue(std::string key, ast::KValue* value)
{
    if (m_readonly) return;

    m_vars[key] = value;
}

kyu::lang::Frame* kyu::lang::Frame::FindValueHolder(std::string key)
{
    if (m_vars.contains(key))
    {
        return this;
    }

    if (m_parent != nullptr)
    {
        return m_parent->FindValueHolder(key);
    }

    return nullptr;
}

kyu::lang::Frame* kyu::lang::Frame::GetParent()
{
    return m_parent;
}