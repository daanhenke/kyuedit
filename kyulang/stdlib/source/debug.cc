#include "debug.hh"
#include <chrono>
#include <iostream>

DEFINE_STDFUNC(kyu::lang::stdlib::debug::enable)
{
    return new ast::KTrue();
}

DEFINE_STDFUNC(kyu::lang::stdlib::debug::message)
{
    std::cout << "[debug]: ";

    for (auto arg: args)
    {
        std::cout << vm->EvaluateValue(arg)->ToString();
    }

    std::cout << std::endl;

    return new ast::KNil();
}

DEFINE_STDFUNC(kyu::lang::stdlib::debug::timeExpression)
{
    for (auto arg : args)
    {
        std::cout << "Timing expression: " << arg->ToString() << std::endl;
        auto start_time = std::chrono::system_clock::now();
        auto result = vm->EvaluateValue(arg);
        auto end_time = std::chrono::system_clock::now();
        std::chrono::duration<double> duration = end_time - start_time;
        std::cout << "Expression finished, took " << std::fixed << duration.count() << " seconds" << std::endl;

        if (args.size() == 1)
        {
            return result;
        }
        else
        {
            std::cout << "Result: " << result->ToString();
        }
    }

    return new ast::KNil();
}