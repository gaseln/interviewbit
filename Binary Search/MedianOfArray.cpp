#include <iostream>
#include <vector>

//solution was hinted in a discussion

double findMedianSortedArrays(const std::vector<int> &A, const std::vector<int> &B) {
    int N1 = (int) A.size();
    int N2 = (int) B.size();

    if (N1 < N2) {
        return findMedianSortedArrays(B, A);
    }

    int min = 0;
    int max = 2 * N2;
    int int1, int2;

    while (min <= max) {
        int2 = (min + max) / 2;
        int1 = N1 + N2 - int2;
        double L1 = (int1 == 0) ? INT_MIN : A[(int1 - 1)/2];
        double R1 = (int1 == 2 * N1) ? INT_MAX : A[int1 /2];
        double L2 = (int2 == 0) ? INT_MIN : B[(int2 - 1)/2];
        double R2 = (int2 == 2 * N2) ? INT_MAX : B[(int2) / 2];

        if (L1 > R2) {
            min = int2 + 1;
        } else if (R1 < L2) {
            max = int2 - 1;
        } else {
            return (std::max(L1, L2) + std::min(R1, R2))/2;
        }
    }

    return -1;
}