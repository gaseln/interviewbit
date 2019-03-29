#include <iostream>
#include <vector>

bool isPossible(std::vector<int> &A, int B, long long n) {
    //std::cout << "isPossible: " << n << std::endl;
    long long tmp = 0;
    auto it = A.begin();
    for (int i = 0; i < B - 1; ++i) {
        tmp = 0;
        while (it != A.end()) {
            if (*it > n) {
                return false;
            }

            if (tmp + *it > n) {
                break;
            } else {
                tmp += *it;
                ++it;
            }
        }
    }
    tmp = 0;
    while (it != A.end()) {
        tmp += *it;
        ++it;
    }
    return (tmp <= n);
}

int books(std::vector<int> &A, int B) {
    long long min = 0;
    long long max = INT_MAX;
    long long mid = 0;

    if (A.size() < B) {
        return -1;
    }

    while (min < max) {
        mid = min + (max - min) / 2;
        bool lower = isPossible(A, B, mid);
        bool upper = isPossible(A, B, mid + 1);
        //std::cout << lower << " " << upper << std::endl;
        if (!lower && upper) {
            return (int) mid + 1;
        } else if (lower) {
            max = mid;
        } else {
            min = mid + 1;
        }
    }
}

int main() {
    std::vector<int> A = {12, 34, 67, 90};
    auto res = books(A, 2);
    std::cout << "RESULT: " << res;
    return 0;
}
