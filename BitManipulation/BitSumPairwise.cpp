#include <iostream>
#include <vector>
#include <math.h>

int cntBits(std::vector<int>& B) {
    std::vector<unsigned int> A(B.size());
    for (int i = 0; i < A.size(); ++i) {
        A[i] = (unsigned int) B[i];
    }
    std::sort(A.begin(), A.end());
    unsigned int x;

    if (A.size()==0) {
        return 0;
    }
    unsigned long size = 0;

    unsigned int A_max = A[A.size() - 1];

    if (A_max == UINT_MAX) {
        size = ceil(log(UINT_MAX)/log(2));
    } else {
        size = ceil(log(A_max + 1)/log(2));
    }


    std::vector<unsigned int> ones(size);
    for (auto num : A) {
        while (num != 0) {
            x = num & ~(num - 1);
            ones[log(x)/log(2)] += 1;
            num = num & (num - 1);
        }
    }

    int res = 0;
    for (auto val : ones) {
        res += 2 * (A.size() - val) * val % 1000000007;
        res = res % 1000000007;
    }

    return res % 1000000007;
}

int main() {
    std::vector<int> A = {0, 1};
    std::cout << cntBits(A) << std::endl;
    return 0;
}
