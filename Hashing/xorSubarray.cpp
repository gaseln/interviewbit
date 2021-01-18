#include <iostream>
#include <vector>
#include <unordered_map>


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

int solve(std::vector<int>& arr, int B) {
    int result = 0;
    size_t arr_size = arr.size();
    std::vector<int> xor_array(arr_size + 1);
    xor_array[0] = 0;
    for (size_t i = 1; i < arr_size + 1; ++i) {
        xor_array[i] = xor_array[i - 1] xor arr[i - 1];
    }
    std::unordered_map<int, int> count;
    int tmp;
    for (auto& el : xor_array) {
        count[el] += 1;
    }
    for (auto& el : xor_array) {
        tmp = el xor B;
        if (count.find(tmp) != count.end()) {
            result += count[tmp];
        }
    }
    result /= 2;
    return result;
}

int main() {
    std::vector<int> arr = {5, 6, 7, 8, 9};
    auto res = solve(arr, 5);
    std::cout << res;
}