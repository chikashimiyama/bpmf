#include "VerbosePrinter.h"

#include <sstream>

namespace bpmf::core
{
    VerbosePrinter::VerbosePrinter(const std::vector<Result>& results, const BPMRange& bpmRange)
    : results_(results)
    , bpmRange_(bpmRange)
    {
    }

    std::string VerbosePrinter::print() const
    {
        auto ss = std::stringstream();
        for(const auto& result : results_)
        {
            ss << "--------------------------" << "\n"
            << "        Input: " << result.input << "\n"
            << "Abs file path: " << (result.path.has_value() ? result.path.value().string() : "unknown") << "\n"
            << "Estimated BPM: " << (result.estimatedBPM.has_value() ? std::to_string(result.estimatedBPM.value()) : "unknown") << "\n";
        }

        ss << "--------------------------" << "\n";
        ss << "== list of files whose BPM=" << std::to_string(bpmRange_.min) << "~" << std::to_string(bpmRange_.max) << "==\n";
        for(const auto& result : results_)
        {
            if(!result.estimatedBPM.has_value())
                continue;

            const auto estimatedBPM = result.estimatedBPM.value();
            if(bpmRange_.min < estimatedBPM && estimatedBPM< bpmRange_.max && result.path.has_value())
                ss << result.path.value() << "\n";
        }
        return ss.str();
    }
}