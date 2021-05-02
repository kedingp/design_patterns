#include "design_patterns/singleton.h"
#include "gtest/gtest.h"

namespace {
TEST(Singleton, Dummy) {
    auto* mySingleton = &design_patterns::MySingleton::getInstance();
    ASSERT_TRUE(mySingleton);
}
} // namespace