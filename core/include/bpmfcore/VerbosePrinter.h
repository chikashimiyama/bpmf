#pragma once

#include <vector>

#include "IPrinter.h"
#include "Result.h"
#include "Configuration.h"

namespace bpmf::core
{
    class VerbosePrinter : public IPrinter
    {
    public:
        explicit VerbosePrinter(const std::vector<Result>& results, const BPMRange& bpmRange);

        ~VerbosePrinter() override = default;

        std::string print() const override;

    private:
        const std::vector<Result>& results_;
        const BPMRange bpmRange_;
    };
}