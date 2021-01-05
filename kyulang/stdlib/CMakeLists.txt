project(kyulang-stdlib)

add_library(kyulang-stdlib)
add_library(kyu::lang::stdlib ALIAS kyulang-stdlib)

target_sources(kyulang-stdlib
    PRIVATE
        source/stdlib.cc
        source/number.cc
        source/string.cc
        source/debug.cc
        source/logic.cc
)

target_include_directories(kyulang-stdlib PUBLIC include)
target_link_libraries(kyulang-stdlib kyulang-core)
