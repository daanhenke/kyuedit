#include "stdlib.hh"
#include "number.hh"
#include "string.hh"
#include "debug.hh"
#include "logic.hh"
#include "map.hh"

#define ADD_NATIVE(name, func) builtins->SetValue(name, new ast::KNativeFunction(name, func))

void kyu::lang::stdlib::UseForVm(VirtualMachine *vm)
{
    auto builtins = vm->GetBuiltinsFrame();

    builtins->SetValue("nil", new ast::KNil());
    builtins->SetValue("true", new ast::KTrue());
    builtins->SetValue("false", new ast::KFalse());

    ADD_NATIVE("add", number::add);
    ADD_NATIVE("+", number::add);

    ADD_NATIVE("subtract", number::subtract);
    ADD_NATIVE("-", number::subtract);

    ADD_NATIVE("concat", string::concat);

    ADD_NATIVE("debug-enable", debug::enable);
    ADD_NATIVE("debug-message", debug::message);
    ADD_NATIVE("debug-time-expression", debug::timeExpression);

    ADD_NATIVE("if", logic::_if);
    ADD_NATIVE("equal", logic::equal);
    ADD_NATIVE("subroutine", logic::subroutine);
    ADD_NATIVE("local", logic::local);
    ADD_NATIVE("global", logic::global);

    ADD_NATIVE("map", map::newMap);
    ADD_NATIVE("map-set", map::mapSet);
    ADD_NATIVE("map-keys", map::mapKeys);
}