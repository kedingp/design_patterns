#include "hello.h"
#include "gtest/gtest.h"

namespace {
TEST(Foo, Bar) {
    hello("FooBar");
    ASSERT_TRUE(false);
}
} // namespace