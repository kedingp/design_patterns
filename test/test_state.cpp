#include "design_patterns/state.h"
#include "gtest/gtest.h"

using testing::internal::CaptureStdout;
using testing::internal::GetCapturedStdout;

namespace {
TEST(StatePattern, AllStatesAndTransitions) {
    design_patterns::CokeDispenser<design_patterns::State,
                                   design_patterns::Event,
                                   design_patterns::Transitions>
        cokeDispenser;
    CaptureStdout();
    cokeDispenser.dispatch(design_patterns::PushOnOffButton{});
    ASSERT_EQ(GetCapturedStdout(), "Turn-on machine ...\n");

    CaptureStdout();
    cokeDispenser.dispatch(design_patterns::PushCokeButton{});
    ASSERT_EQ(GetCapturedStdout(), "Start serving coke ...\n");

    CaptureStdout();
    cokeDispenser.dispatch(design_patterns::PushOnOffButton{});
    ASSERT_EQ(GetCapturedStdout(), "Can not be handled ...\n");

    CaptureStdout();
    cokeDispenser.dispatch(design_patterns::PushCokeButton{});
    ASSERT_EQ(GetCapturedStdout(), "Stop serving coke ...\n");

    CaptureStdout();
    cokeDispenser.dispatch(design_patterns::PushOnOffButton{});
    ASSERT_EQ(GetCapturedStdout(), "Turn-off machine ...\n");
}
} // namespace