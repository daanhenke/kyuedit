project(program)

add_executable(kyuedit)

target_sources(kyuedit
    PRIVATE
        source/main.cc
)

target_link_libraries(kyuedit kyu::lang::core kyu::lang::stdlib)