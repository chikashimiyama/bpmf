#include "Printer.h"

#include <sstream>

namespace bpmf::core
{
    Printer::Printer(const std::vector<Result> &results, const BPMRange& bpmRange)
    : results_(results)
    , bpmRange_(bpmRange)
    {
    }

    std::string Printer::print() const
    {
        auto ss = std::stringstream();

        for(const auto& result : results_)
        {
            if(!result.estimatedBPM.has_value())
                continue;

            const auto estimatedBPM = result.estimatedBPM.value();
            if(bpmRange_.min < estimatedBPM && estimatedBPM< bpmRange_.max && result.path.has_value())
                ss << result.path.value();
        }
        return ss.str();
    }
}