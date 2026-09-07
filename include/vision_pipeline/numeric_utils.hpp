#pragma once

#include <ranges>
#include <vector>

namespace vision_pipeline {

// Returns the first `count` positive integers divisible by both `a` and `b`.
inline std::vector<int> multiples_of_both(int a, int b, int count) {
    return std::views::iota(1) |
        std::views::filter([a, b](int val) { return val % a == 0 and val % b == 0; }) |
        std::views::take(count) |
        std::ranges::to<std::vector>();
}

} // namespace vision_pipeline
