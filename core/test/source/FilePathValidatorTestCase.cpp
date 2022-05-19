#include <gtest/gtest.h>

#include <ostream>
#include <fstream>
#include <bpmfcore/FilePathValidator.h>

namespace bpmf::core
{
    using namespace testing;

    TEST(UnitTest_FileValidator, construction_file_not_exist)
    {
        auto validator = FilePathValidator("/tmp/to/not/existing/file.mp3");

        EXPECT_EQ(std::nullopt, validator.getFilePath());
    }

    TEST(UnitTest_FileValidator, construction_non_regular_file)
    {
        auto path = std::filesystem::path("/tmp/unit_test_file_validator");
        std::filesystem::create_directory(path);

        auto validator = FilePathValidator(path.string());

        EXPECT_EQ(std::nullopt, validator.getFilePath());
        std::filesystem::remove_all(path);
    }

    TEST(UnitTest_FileValidator, construction)
    {
        auto path = std::filesystem::path("/tmp/testfile.txt");
        auto outfile = std::ofstream(path);
        outfile.close();

        auto validator = FilePathValidator(path.string());

        EXPECT_NE(std::nullopt, validator.getFilePath());
        std::filesystem::remove(path);
    }
}

