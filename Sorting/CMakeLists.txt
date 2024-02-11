add_executable(SortTests SortTests.cpp)
target_link_libraries(SortTests GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(SortTests)