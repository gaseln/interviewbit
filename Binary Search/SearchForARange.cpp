#include <iostream>
#include <vector>


std::vector<int> searchRange(const std::vector<int> &A, int B) {
    int min = 0;
    int max = (int) A.size() - 1;
    int intermediate;
    int l_ind, u_ind;

    if (A[0] > B) {
        return {-1, -1};
    }

    if (A[max] < B) {
        return {-1, -1};
    }

    while (min < max) {
        intermediate = min + (max - min) / 2;
        if (A[intermediate] <= B - 1) {
            min = intermediate + 1;
        } else {
            max = intermediate;
        }
    }

    if (A[min] != B) {
        return {-1, -1};
    }

    l_ind = min;

    min = 0; max = (int) A.size() - 1;

    while (min < max) {
        intermediate = min + (max - min + 1) / 2;
        if (A[intermediate] <= B) {
            min = intermediate;
        } else {
            max = intermediate - 1;
        }
    }

    u_ind = min;

    return {l_ind, u_ind};

}

int main() {
    std::vector<int> A = {5, 7, 7, 8, 8, 10};
    auto res = searchRange(A, 11);
    std::cout << res[0] << " " << res[1] << std::endl;
    return 0;
}