#include <gtest/gtest.h>
#include "SortUtils.hpp"
#include "MergeSort.hpp"

#define INPUT_LIST_SIZE 10

TEST(MergeSortTest, SortingTest) {
    std::vector<int> input_list;
    SortUtils::GenerateInputList(input_list, INPUT_LIST_SIZE);

    MergeSort merge_sort;
    merge_sort.Sort(input_list);

    for (size_t i = 0; i < input_list.size(); ++i) {
        EXPECT_EQ(input_list[i], i + 1);
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
