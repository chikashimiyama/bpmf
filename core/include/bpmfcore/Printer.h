#pragma once

#include <vector>

#include "IPrinter.h"
#include "Result.h"
#include "Configuration.h"

namespace bpmf::core
{
    class Printer : public IPrinter
    {
    public:
        explicit Printer(const std::vector<Result>& results, const BPMRange& bpmRange);

        ~Printer() override = default;

        std::string print() const override;

    private:
        const BPMRange bpmRange_;
        const std::vector<Result>& results_;
    };
}