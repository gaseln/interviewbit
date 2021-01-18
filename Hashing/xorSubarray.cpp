#include <iostream>
#include <vector>


std::vector<int> xorQueries(std::vector<int>& arr, std::vector<std::vector<int>>& queries) {
    size_t arr_size = arr.size();
    std::vector<int> xor_array(arr_size + 1);
    xor_array[0] = 0;
    for (size_t i = 1; i < arr_size + 1; ++i) {
        xor_array[i] = xor_array[i - 1] xor arr[i - 1];
    }

    arr_size = queries.size();
    std::vector<int> results(arr_size);
    for (size_t i = 0; i < arr_size; ++i) {
        results[i] = xor_array[queries[i][0]] xor xor_array[queries[i][1] + 1];
    }

    return results;
}

int main() {
    std::vector<int> arr = {1,3,4,8};
    std::vector<std::vector<int>> q = {{0,1},{1,2},{0,3},{3,3}};
    auto res = xorQueries(arr, q);
    for (auto& el : res) {
        std::cout << el << " ";
    }
}