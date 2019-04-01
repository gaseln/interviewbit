#include <iostream>
#include <vector>

double findMedianSortedArrays(const std::vector<int> &A, const std::vector<int> &B) {
    int N1 = (int) A.size();
    int N2 = (int) B.size();

    if (N1 > N2) {
        return findMedianSortedArrays(B, A); //to ensure time complexity does not exceed
    }

    int min = 0;
    int max = 2 * N1;
    int int1, int2;

    while (min <= max) {
        int1 = min + max;
        int2 = N1 + N2 - int1;
        double L1 = (int1 == 0) ? INT_MIN : A[(int1 - 1)/2];
        double R1 = (int1 == 0) ? INT_MIN : A[int1 /2];
        double L2 = (int2 == 0) ? INT_MIN : B[(int2 - 1)/2];
        double R2 = (int2 == 0) ? INT_MIN : B[(int2) / 2];

        if (L1 > R2) {
            max = int1 - 1;
        } else if (R1 < L2) {

        }
    }
}