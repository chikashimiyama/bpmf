#pragma once

#include <vector>
#include "Result.h"

#include "IPrinter.h"

namespace bpmf::core
{
    class VerbosePrinter : public IPrinter
    {
    public:
        explicit VerbosePrinter(const std::vector<Result>& results);

        ~VerbosePrinter() override = default;

        std::string print() const override;

    private:
        const std::vector<Result>& results_;
    };
}