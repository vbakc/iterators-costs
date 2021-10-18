#include <vector>
#include <random>

#include <gtest/gtest.h>

#include <test_set.hpp>

const std::vector<std::int32_t> a = {5, 2, 3, 4, 5, 6, 7, 8, 9, 10};
const std::vector<std::int32_t> b = {-10, 12, 13, 14, 15, 16, 17, 18, 19, -20};
const std::int64_t expected_result = 450;

TEST(TestSet, calculate_direct_iter) {
    ASSERT_EQ(expected_result, calculate_direct_index(a, b));
}

TEST(TestSet, calculate_direct) {
    ASSERT_EQ(expected_result, calculate_direct(a, b));
}

TEST(TestSet, calculate_ranges) {
    ASSERT_EQ(expected_result, calculate_ranges(a, b));
}

TEST(TestSet, calculate_tranform_reduce) {
    ASSERT_EQ(expected_result, calculate_tranform_reduce(a, b));
}

TEST(TestSet, calculate_avx) {
    ASSERT_EQ(expected_result, calculate_avx(a, b));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
