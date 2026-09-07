#include <algorithm>

#include <gtest/gtest.h>

#include "vision_pipeline/numeric_utils.hpp"

TEST(MultiplesOfBoth, ReturnsRequestedCount) {
    // Arrange
    constexpr int a = 3;
    constexpr int b = 4;
    constexpr int count = 5;

    // Act
    auto result = vision_pipeline::multiples_of_both(a, b, count);

    // Assert
    EXPECT_EQ(result.size(), count);
}

TEST(MultiplesOfBoth, FirstResultIsSmallestCommonMultiple) {
    // Arrange
    constexpr int a = 3;
    constexpr int b = 4;

    // Act
    auto result = vision_pipeline::multiples_of_both(a, b, 1);

    // Assert
    ASSERT_FALSE(result.empty());
    EXPECT_EQ(result.front(), 12); // smallest number divisible by both 3 and 4
}

TEST(MultiplesOfBoth, ReturnsMultiplesInAscendingOrder) {
    // Arrange
    constexpr int a = 3;
    constexpr int b = 5;
    constexpr int count = 10;

    // Act
    auto result = vision_pipeline::multiples_of_both(a, b, count);

    // Assert
    EXPECT_TRUE(std::ranges::is_sorted(result));
}

TEST(MultiplesOfBoth, ReturnsEmptyVectorWhenCountIsZero) {
    // Arrange
    constexpr int a = 3;
    constexpr int b = 4;
    constexpr int count = 0;

    // Act
    auto result = vision_pipeline::multiples_of_both(a, b, count);

    // Assert
    EXPECT_EQ(result.size(), 0);
}

TEST(MultiplesOfBoth, ReturnsMultiplesWhenAEqualsB) {
    // Arrange
    constexpr int a = 5;
    constexpr int b = 5;
    constexpr int count = 5;

    // Act
    auto result = vision_pipeline::multiples_of_both(a, b, count);

    // Assert
    const std::vector<int> expected{5, 10, 15, 20, 25};
    EXPECT_EQ(result, expected);
}