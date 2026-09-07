cmake_minimum_required(VERSION 3.28)
project(realtime_vision_pipeline)

include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.15.2
)
FetchContent_MakeAvailable(googletest)

add_executable(realtime_vision_pipeline main.cpp)
target_compile_features(realtime_vision_pipeline PUBLIC cxx_std_23)
target_include_directories(realtime_vision_pipeline PUBLIC include)

enable_testing()
include(GoogleTest)

add_executable(realtime_vision_pipeline_tests tests/numeric_utils_test.cpp)
target_compile_features(realtime_vision_pipeline_tests PUBLIC cxx_std_23)
target_include_directories(realtime_vision_pipeline_tests PUBLIC include)
target_link_libraries(realtime_vision_pipeline_tests PRIVATE GTest::gtest_main)

gtest_discover_tests(realtime_vision_pipeline_tests)
