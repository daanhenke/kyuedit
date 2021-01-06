project(kyulang-core)

add_library(kyulang-core)
add_library(kyu::lang::core ALIAS kyulang-core)

target_sources(kyulang-core
    PRIVATE
        source/Token.cc
        source/Lexer.cc
        source/Parser.cc
        source/Frame.cc
        source/VirtualMachine.cc

        source/ast/KValue.cc
        source/ast/KNumber.cc
        source/ast/KString.cc
        source/ast/KSymbol.cc
        source/ast/KList.cc
        source/ast/KNil.cc
        source/ast/KNativeFunction.cc
        source/ast/KSubroutine.cc
        source/ast/KMap.cc
)

target_include_directories(kyulang-core PUBLIC include)
