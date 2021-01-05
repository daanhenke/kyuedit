#include "ast/KNativeFunction.hh"
#include <sstream>
#include <utility>

kyu::lang::ast::KNativeFunction::KNativeFunction(std::string name, KNativeFunctionCallback callback) : KValue(KValueType::NativeFunction), m_name(std::move(name)), m_callback(callback) {}

std::string kyu::lang::ast::KNativeFunction::ToString()
{
    std::stringstream stream;
    stream << "NativeFunction<" << m_name << "@" << std::hex << (void*) m_callback << ">";
    return stream.str();
}

std::string kyu::lang::ast::KNativeFunction::GetName()
{
    return m_name;
}

kyu::lang::ast::KNativeFunctionCallback kyu::lang::ast::KNativeFunction::GetCallback()
{
    return m_callback;
}