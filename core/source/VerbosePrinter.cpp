#include "VerbosePrinter.h"

#include <sstream>

namespace bpmf::core
{
    VerbosePrinter::VerbosePrinter(const std::vector<Result>& results)
    : results_(results)
    {
    }

    std::string VerbosePrinter::print() const
    {
        auto ss = std::stringstream();
        for(const auto& result : results_)
        {
            ss << "--------------------------" << "\n"
            << "input: " << result.input << "\n"
            << "file path: " << (result.path.has_value() ? result.path.value().string() : "unknown") << "\n"
            << "estimated BPM: " << (result.estimatedBPM.has_value() ? std::to_string(result.estimatedBPM.value()) : "unknown") << "\n";
        }
        return ss.str();
    }
}