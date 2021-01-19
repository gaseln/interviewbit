#include <iostream>
#include <vector>

bool isEven(int& a) {
    return (a % 2 == 0);
}

void initialize_end(std::vector<int>& nums, size_t& end, int& k) {
    size_t counter = 0;
    while (end < nums.size()) {
        while (end < nums.size() && isEven(nums[end])) {end++;}
        if (end == nums.size() || counter == k - 1) {return;}
        counter++; end++;
    }
 }

int numberOfEvenNumbers(std::vector<int>& nums, size_t& it) {
    int res = 1;
    while (it < nums.size() && isEven(nums[it])) {it++; res++;}
    return res;
}

int numberOfSubarrays(std::vector<int>& nums, int k) {
    size_t begin = 0, end = 0;
    initialize_end(nums, end, k);

    int result = 0, a, b;

    if (k == 0) {
        int counter = 0;
        nums.push_back(1);
        for (auto& el : nums) {
            if (isEven(el)) {
                counter++;
            } else {
                result += counter * (counter + 1) / 2;
                counter = 0;
            }
        }
        nums.pop_back();
        return result;
    }

    while (end < nums.size()) {
        a = numberOfEvenNumbers(nums, begin); begin++;
        end++; b = numberOfEvenNumbers(nums, end);

        result += a * b;
    }

    return result;
}

int main() {
    std::vector<int> nums = {68, 32, 52, 35, 212};
    int k = 0;
    std::cout << numberOfSubarrays(nums, k);
}