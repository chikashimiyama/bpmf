#include <vector>
#include <string>
#include <gtest/gtest.h>
#include <bpmfcore/Printer.h>

namespace bpmf::core
{
    using namespace testing;

    class UnitTest_Printer : public Test
    {
    protected:
        std::vector<Result> results_;
        BPMRange bpmRange_{90, 120};
    };

    TEST_F(UnitTest_Printer, print)
    {
        results_.push_back({
            "my.mp3",
            "/home/mike/my.mp3",
            100,
        });

        auto printer = Printer(results_, bpmRange_);
        auto output = printer.print();
        EXPECT_EQ("\"/home/mike/my.mp3\"", output);
    }

    TEST_F(UnitTest_Printer, print_multiple)
    {
        results_.push_back({
            "my.mp3",
            "/home/mike/my.mp3",
            100,
        });

        results_.push_back({
            "your.mp3",
            "/home/mike/your.mp3",
            105,
        });

        auto printer = Printer(results_, bpmRange_);
        auto output = printer.print();
        EXPECT_EQ("\"/home/mike/my.mp3\"\n\"/home/mike/your.mp3\"", output);
    }

    TEST_F(UnitTest_Printer, print_no_match)
    {
        results_.push_back({
            "my.mp3",
            "/home/mike/my.mp3",
            190,
        });

        auto printer = Printer(results_, bpmRange_);
        auto output = printer.print();
        EXPECT_TRUE(output.empty());
    }

    TEST_F(UnitTest_Printer, print_invalid_bpm)
    {
        results_.push_back({
            "my.mp3",
            "/home/mike/my.mp3",
            std::nullopt,
        });

        auto printer = Printer(results_, bpmRange_);
        auto output = printer.print();
        EXPECT_TRUE(output.empty());
    }
}

