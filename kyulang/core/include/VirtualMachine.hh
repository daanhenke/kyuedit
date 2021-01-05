#pragma once
#include "Frame.hh"
#include "Parser.hh"
#include "ast/KNil.hh"
#include "ast/KNativeFunction.hh"
#include "ast/KSubroutine.hh"

namespace kyu::lang
{
    class VirtualMachine
    {
    protected:
        Parser m_parser;
        Frame* m_builtins_frame;
        Frame* m_global_frame;
        Frame* m_current_frame;

    public:
        VirtualMachine();

        void EvaluateString(std::string source);

        ast::KValue* EvaluateValue(ast::KValue* input);

        ast::KValue* ResolveSymbol(ast::KSymbol* symbol);
        void UpdateSymbol(ast::KSymbol* symbol, ast::KValue* value);

        Frame* GetBuiltinsFrame();
        Frame* GetGlobalFrame();
        Frame* GetCurrentFrame();
    };
}