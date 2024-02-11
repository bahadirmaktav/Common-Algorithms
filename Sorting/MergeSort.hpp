#ifndef MERGE_SORT_HPP_
#define MERGE_SORT_HPP_

#include <vector>
#include <stdint.h>

class MergeSort {
public:
    void Sort(std::vector<int>& input_list) {
        RecursiveSort(input_list, 0, input_list.size() - 1);
    }
private:
    void RecursiveSort(std::vector<int>& input_list, size_t left_index, size_t right_index) {
        if (left_index >= right_index) {
            return;
        }
        size_t middle_index = (left_index + right_index) / 2;
        RecursiveSort(input_list, left_index, middle_index);
        RecursiveSort(input_list, middle_index + 1, right_index);
        Merge(input_list, left_index, middle_index, right_index);
    }
    void Merge(std::vector<int>& input_list, size_t left_index, size_t middle_index, size_t right_index) {
        // Create copies of left and right subarrays.
        std::vector<int> left_subarray;
        std::vector<int> right_subarray;
        for (size_t il = left_index; il <= middle_index; ++il) {
            left_subarray.push_back(input_list[il]);
        }
        for (size_t ir = middle_index + 1; ir <= right_index; ++ir) {
            right_subarray.push_back(input_list[ir]);
        }
        // Define index iterators
        // INFO(MBM): left_index used as a input_list iterator
        size_t left_subarray_size = left_subarray.size();
        size_t right_subarray_size = right_subarray.size();
        size_t l_iter = 0;
        size_t r_iter = 0;
        // Sort and update the input_list
        while (l_iter < left_subarray_size && r_iter < right_subarray_size) {
            if (left_subarray[l_iter] < right_subarray[r_iter]) {
                input_list[left_index] = left_subarray[l_iter];
                l_iter++;
            } else {
                input_list[left_index] = right_subarray[r_iter];
                r_iter++;
            }
            left_index++;
        }
        while (l_iter < left_subarray_size) {
            input_list[left_index] = left_subarray[l_iter];
            l_iter++;
            left_index++;
        }
        while (r_iter < right_subarray_size) {
            input_list[left_index] = right_subarray[r_iter];
            r_iter++;
            left_index++;
        }
    }
};

#endif // MERGE_SORT_HPP_