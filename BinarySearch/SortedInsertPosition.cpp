#include <iostream>
#include <vector>

int searchInsert(std::vector<int> &A, int B) {
    int min = 0;
    int max = (int) A.size() - 1;
    int intermediate;

    if (A[0] > B) {
        return 0;
    }

    if (A[max] < B) {
        return max + 1;
    }

    while (min < max) {
        intermediate = min + (max - min) / 2;
        if (A[intermediate] <= B - 1) {
            min = intermediate + 1;
        } else {
            max = intermediate;
        }
    }

    return min;
}

int main() {
    std::vector<int> A = {1, 3, 5, 6};
    std::cout << searchInsert(A, 0) << std::endl;
    return 0;
}
