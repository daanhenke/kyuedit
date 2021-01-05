#include <iostream>
#include "VirtualMachine.hh"
#include "stdlib.hh"

int main(int argc, const char** argv)
{
    std::cout << "Hello" << std::endl;

    kyu::lang::VirtualMachine vm;
    kyu::lang::stdlib::UseForVm(&vm);

    while (true)
    {
        std::cout << "> ";
        std::string query;
        std::getline(std::cin, query);
        vm.EvaluateString(query);
    }

    return 0;
}