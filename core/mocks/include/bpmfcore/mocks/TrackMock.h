#pragma once

#include <gmock/gmock.h>

#include "bpmfcore/ITrack.h"

namespace bpmf::core
{
    class TrackMock : public ITrack {

    public:
        MOCK_METHOD(float, getSampleRate, (), (const, override));

        MOCK_METHOD(const std::vector<float>&, getSamples, (), (const, override));
    };

}  // namespace bpmf::core
