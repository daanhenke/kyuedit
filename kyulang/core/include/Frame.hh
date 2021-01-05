#pragma once
#include <map>
#include <string>
#include "ast/KValue.hh"

namespace kyu::lang
{
    class Frame
    {
    protected:
        bool m_readonly;
        Frame* m_parent;
        std::map<std::string, ast::KValue*> m_vars;

    public:
        Frame(Frame* parent = nullptr, bool readOnly = false);

        ast::KValue* GetValue(std::string key);
        void SetValue(std::string key, ast::KValue* value);

        Frame* FindValueHolder(std::string key);
        Frame* GetParent();
    };
}