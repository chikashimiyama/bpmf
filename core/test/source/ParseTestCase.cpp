#include <vector>
#include <string>
#include <gtest/gtest.h>
#include <bpmfcore/Main.h>

namespace bpmf::core
{
    using namespace testing;

    TEST(UnitTest_Parser, parse)
    {
        const auto argv = std::array<const char*, 4>{"/working/dir", "30", "100", "/path/to/mp3"};
        auto instruction = std::string();
        auto configuration = parse(argv.size(), argv.data(), instruction);

        EXPECT_TRUE(configuration.has_value());
        EXPECT_FALSE(configuration.value().verbose);
        EXPECT_EQ(30, configuration.value().bpmRange.min);
        EXPECT_EQ(100, configuration.value().bpmRange.max);
        EXPECT_EQ("/path/to/mp3", configuration.value().paths.front());
        EXPECT_TRUE(instruction.size() > 0);
    }

    TEST(UnitTest_Parser, parse_multiple_paths)
    {
        const auto argv = std::array<const char*, 5>{"/working/dir", "30", "100", "/path/to/mp3", "path/to/another/mp3"};
        auto instruction = std::string();
        auto configuration = parse(argv.size(), argv.data(), instruction);

        EXPECT_TRUE(configuration.has_value());
        EXPECT_FALSE(configuration.value().verbose);
        EXPECT_EQ(30, configuration.value().bpmRange.min);
        EXPECT_EQ(100, configuration.value().bpmRange.max);
        EXPECT_EQ(2, configuration.value().paths.size());
        EXPECT_TRUE(instruction.size() > 0);
    }

    TEST(UnitTest_Parser, parse_verbose)
    {
        const auto argv = std::array<const char*, 5>{"/working/dir", "-v", "30", "100", "/path/to/mp3"};
        auto instruction = std::string();
        auto configuration = parse(argv.size(), argv.data(), instruction);

        EXPECT_TRUE(configuration.has_value());
        EXPECT_TRUE(configuration.value().verbose);
        EXPECT_EQ(30, configuration.value().bpmRange.min);
        EXPECT_EQ(100, configuration.value().bpmRange.max);
        EXPECT_EQ("/path/to/mp3", configuration.value().paths.front());
        EXPECT_TRUE(instruction.size() > 0);
    }

    TEST(UnitTest_Parser, no_file)
    {
        const auto argv = std::array<const char*, 3>{"/working/dir", "30", "100"};
        auto instruction = std::string();
        auto configuration = parse(argv.size(), argv.data(), instruction);

        EXPECT_FALSE(configuration.has_value());
    }

    TEST(UnitTest_Parser, insufficient_range)
    {
        const auto argv = std::array<const char*, 3>{"/working/dir", "30", "/path/to/mp3"};
        auto instruction = std::string();
        auto configuration = parse(argv.size(), argv.data(), instruction);

        EXPECT_FALSE(configuration.has_value());
    }

    TEST(UnitTest_Parser, no_range)
    {
        const auto argv = std::array<const char*, 2>{"/working/dir", "/path/to/mp3"};
        auto instruction = std::string();
        auto configuration = parse(argv.size(), argv.data(), instruction);

        EXPECT_FALSE(configuration.has_value());
    }

    TEST(UnitTest_Parser, no_args)
    {
        const auto argv = std::array<const char*, 1>{"/working/dir"};
        auto instruction = std::string();
        auto configuration = parse(argv.size(), argv.data(), instruction);

        EXPECT_FALSE(configuration.has_value());
    }
}

