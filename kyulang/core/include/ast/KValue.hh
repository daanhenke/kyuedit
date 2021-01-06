#pragma once
#include <string>

namespace kyu::lang::ast
{
    typedef enum KValueType
    {
        Number,
        String,
        Symbol,
        List,
        Nil,
        NativeFunction,
        Subroutine,
        Map
    } KValueType;

    class KValue
    {
    protected:
        KValueType m_type;

        explicit KValue(KValueType type);

    public:
        virtual std::string ToString() = 0;
        KValueType GetType();
    };
}