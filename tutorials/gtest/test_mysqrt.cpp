#include "gtest/gtest.h"
#include "mysqrt.hpp"
#include <cmath>
#include <stdexcept>

// anonymous namespace
namespace {
  TEST(mysqrtTest, correctResult) {
    ASSERT_DOUBLE_EQ(2.0, mysqrt(4.0));
    ASSERT_DOUBLE_EQ(sqrt(3.0), mysqrt(3.0));
  }

  TEST(mysqrtTest, zero) {
    ASSERT_DOUBLE_EQ(0.0, mysqrt(0.0));
  }

  TEST(mysqrtTest, negative) {
    ASSERT_THROW(mysqrt(-1.0), std::logic_error);
  }
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
