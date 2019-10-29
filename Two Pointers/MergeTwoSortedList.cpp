#include <iostream>
#include <vector>

void merge(std::vector<int>& nums1, std::vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();
    std::vector<int> res;
    int ind1 = 0;
    int ind2 = 0;
    while ((ind1 < m) or (ind2 < n)) {
        bool first_array = true;

        if (ind1 == m) {
            first_array = false;
        } else if (ind2 != n) {
               first_array = (nums1[ind1] < nums2[ind2]);
        }

        if (first_array) {
            res.push_back(nums1[ind1]);
            ind1++;
        } else {
            res.push_back(nums2[ind2]);
            ind2++;
        }
    }

    nums1 = res;
}


int main() {

    std::vector<int> A = {1, 2, 4, 6, 10};
    std::vector<int> B = {1, 2, 3, 7, 9};
    merge(A, B);
    for (auto el : A) {
        std::cout << el << " ";
    }

    return 0;
}