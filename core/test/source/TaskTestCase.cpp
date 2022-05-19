#include <gmock/gmock.h>

#include <bpmfcore/mocks/FactoryMock.h>
#include <bpmfcore/mocks/FilePathValidatorMock.h>
#include <bpmfcore/mocks/TrackMock.h>
#include <bpmfcore/mocks/AnalyzerMock.h>

#include <bpmfcore/Task.h>

namespace bpmf::core
{
    using namespace testing;

    class UnitTest_Task : public Test
    {
    protected:
        void SetUp() override
        {
            filePathValidatorMock_ = std::make_unique<FilePathValidatorMock>();
            filePathValidatorMockPtr_ = filePathValidatorMock_.get();

            trackMock_ = std::make_unique<TrackMock>();

            analyzerMock_ = std::make_unique<AnalyzerMock>();
            analyzerMockPtr_ = analyzerMock_.get();

            ON_CALL(factoryMock_, createFilePathValidator(_))
               .WillByDefault(Return(ByMove(std::move(filePathValidatorMock_))));

            ON_CALL(factoryMock_, createTrack(_))
               .WillByDefault(Return(ByMove(std::move(trackMock_))));

            ON_CALL(factoryMock_, createAnalyzer(_))
               .WillByDefault(Return(ByMove(std::move(analyzerMock_))));
        }

        void TearDown() override
        {
            filePathValidatorMock_ = nullptr;
        }

        std::unique_ptr<FilePathValidatorMock> filePathValidatorMock_;
        FilePathValidatorMock* filePathValidatorMockPtr_;

        std::unique_ptr<TrackMock> trackMock_;

        std::unique_ptr<AnalyzerMock> analyzerMock_;
        AnalyzerMock* analyzerMockPtr_;

        NiceMock<FactoryMock> factoryMock_;
    };

    TEST_F(UnitTest_Task, execute_invalid_filepath)
    {
        EXPECT_CALL(factoryMock_, createFilePathValidator("mysong.mp3"));
        EXPECT_CALL(*filePathValidatorMockPtr_, getFilePath()).WillOnce(Return(std::nullopt));

        auto task = Task("mysong.mp3", factoryMock_);
        auto result = task.execute();

        EXPECT_EQ("mysong.mp3", result.input);
        EXPECT_EQ(std::nullopt, result.path);
        EXPECT_EQ(std::nullopt, result.estimatedBPM);
    }

    TEST_F(UnitTest_Task, execute)
    {
        EXPECT_CALL(factoryMock_, createFilePathValidator("mysong.mp3"));
        EXPECT_CALL(*filePathValidatorMockPtr_, getFilePath())
           .WillOnce(Return(std::filesystem::path("/home/mike/mysong.mp3")));
        EXPECT_CALL(factoryMock_, createTrack(_));
        EXPECT_CALL(factoryMock_, createAnalyzer(_));
        const auto estimatedBPM = std::optional<double>(120.0);
        EXPECT_CALL(*analyzerMockPtr_, getBPM()).WillOnce(ReturnRef(estimatedBPM));

        auto task = Task("mysong.mp3", factoryMock_);
        auto result = task.execute();

        EXPECT_EQ("mysong.mp3", result.input);
        EXPECT_EQ("/home/mike/mysong.mp3", result.path);
        EXPECT_EQ(120.0, result.estimatedBPM);
    }

}