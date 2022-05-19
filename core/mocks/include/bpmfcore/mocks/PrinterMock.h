#pragma once

#include <gmock/gmock.h>
#include "bpmfcore/IPrinter.h"

namespace bpmf::core
{

    class PrinterMock : public IPrinter
    {
    public:
        ~PrinterMock() = default;

        MOCK_METHOD(std::string, print, (), (const, override));
    };

}  // namespace bpmf::core
