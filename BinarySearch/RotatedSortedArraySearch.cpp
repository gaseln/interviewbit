#include <iostream>
#include <vector>

int search(std::vector<int>& A, int B) {
    int min = 0;
    int max = (int) A.size() - 1;
    int intermediate;
    bool to_left = false;

    if (max < 0) {
        return -1;
    }

    if (A[0] > B and A[max] < B) {
        return -1;
    }

    if (A[0] <= B) {
        to_left = true;
    }

    while (min < max) {
        intermediate = min + (max - min + 1) / 2;

        if (to_left) {
            if (A[intermediate] < A[0]) {
                max = intermediate - 1;
            } else {
                if (A[intermediate] > B) {
                    max = intermediate - 1;
                } else {
                    min = intermediate;
                }
            }
        } else {
            if (A[intermediate] > A[A.size() - 1]) {
                min = intermediate;
            } else {
                if (A[intermediate] > B) {
                    max = intermediate - 1;
                } else {
                    min = intermediate;
                }
            }
        }
    }

    return (A[min] == B) ? min : -1;
}

int main() {
    std::vector<int> A = {};
    std::cout << search(A, 8) << std::endl;
    return 0;
}