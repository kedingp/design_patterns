#include "design_patterns/state.h"
#include "gtest/gtest.h"

namespace {
TEST(StatePattern, Dummy) {
    design_patterns::CokeDispenser<design_patterns::State,
                                   design_patterns::Event,
                                   design_patterns::Transitions>
        cokeDispenser;
    cokeDispenser.dispatch(design_patterns::PushOnOffButton{});
    cokeDispenser.dispatch(design_patterns::PushCokeButton{});
    cokeDispenser.dispatch(design_patterns::PushOnOffButton{});
    cokeDispenser.dispatch(design_patterns::PushCokeButton{});
    cokeDispenser.dispatch(design_patterns::PushOnOffButton{});
    ASSERT_TRUE(false);
}
} // namespace