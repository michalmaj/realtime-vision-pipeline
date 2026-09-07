#include <print>

#include "vision_pipeline/numeric_utils.hpp"

int main() {
    auto vec = vision_pipeline::multiples_of_both(3, 3, 3);
    std::println("{}", vec);
    return 0;
}
