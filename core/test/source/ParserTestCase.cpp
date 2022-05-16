#include <gtest/gtest.h>

#include <bpmfcore/Parser.h>

namespace bpmf::core
{
    TEST(UnitTest_Parser, parse)
    {
        auto args = std::vector<const char*>{"/home/mike/bpmf", "30", "200", "/home/mike/test.mp3"};
        auto configuration = parse(static_cast<int>(args.size()), args.data());
        EXPECT_TRUE(configuration.validity);
        EXPECT_EQ(30, configuration.minBPM);
        EXPECT_EQ(200, configuration.maxBPM);
        EXPECT_EQ("/home/mike/bpmf", configuration.applicationPath);
        EXPECT_EQ("/home/mike/test.mp3", configuration.paths[0]);
    }

    TEST(UnitTest_Parser, parse_no_arguments)
    {
        const auto* path = "/home/mike/bpmf";
        auto configuration = parse(1, &path);
        EXPECT_FALSE(configuration.validity);
    }

    TEST(UnitTest_Parser, parse_too_few_arguments)
    {
        auto args = std::vector<const char*>{"/home/mike/bpmf", "30", "200"};
        auto configuration = parse(3, args.data());
        EXPECT_FALSE(configuration.validity);
    }


}