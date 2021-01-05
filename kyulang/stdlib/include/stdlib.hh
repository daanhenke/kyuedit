#pragma once
#include "VirtualMachine.hh"

#define DEFINE_STDFUNC(name) kyu::lang::ast::KValue* name(kyu::lang::VirtualMachine* vm, const kyu::lang::ast::ValueVector& args)

namespace kyu::lang::stdlib
{
    void UseForVm(VirtualMachine* vm);
}