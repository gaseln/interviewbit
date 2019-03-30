#include <iostream>
#include <vector>

int search(std::vector<int>& A, int B) {
    int min = 0;
    int max = (int) A.size() - 1;
    int intermediate;
    bool to_left = false;

    if (A[0] > B and A[max] < B) {
        return -1;
    }

    if (A[0] <= B) {
        to_left = true;
    }

}