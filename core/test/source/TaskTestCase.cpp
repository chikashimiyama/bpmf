#include <gmock/gmock.h>

#include <bpmfcore/Task.h>

namespace bpmf::core
{
    using namespace testing;

    class UnitTest_Task : public Test
    {
    protected:
        void SetUp() override
        {
            Test::SetUp();
        }

        void TearDown() override
        {
            Test::TearDown();
        }

    };

}