#include <iostream>

int sqrt(int n) {
    long long start = 0;
    long long end = n;
    long long middle = 0;
    long long middle_sq = 0;
    while (start <= end) {
        middle = (start + end) / 2;

        middle_sq = middle * middle;

        if ((middle_sq <= n) && (middle + 1) * (middle + 1) > n) {
            return (int) middle;
        }

        if (middle_sq < n) {
            start = middle + 1;
        } else {
            end = middle - 1;
        }
    }
    return -1;
}

int main() {
    std::cout << sqrt(1) << std::endl;
    return 0;
}
