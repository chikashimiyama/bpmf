#pragma once

#include <memory>

namespace bpmf::core
{
    class IPrinter
    {
    public:
        virtual ~IPrinter() = default;

        virtual std::string print() const = 0;
    };

    using PrinterPtr = std::unique_ptr<IPrinter>;
}
