#include <iostream>

#include "bpmfcore/Main.h"
#include "Factory.h"

using namespace bpmf;

int main(int argc, char** argv)
{
    std::string instruction;
    const auto configuration = core::parse(argc, argv, instruction);
    if(!configuration.has_value())
    {
        std::cout << instruction << std::endl;
        return 1;
    }

    const auto factory = Factory();
    const auto results = core::process(configuration.value(), factory);
    std::cout << core::print(configuration.value(), results, factory) << std::endl;
    return 0;
}
