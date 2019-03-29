#include <iostream>
#include <vector>

bool isPossible(long long T, int A, std::vector<int> &C) {
    int counter = 0;
    int index = 0;
    bool isPossible = true;

    for (int i = 0; i < A; ++i) {
        while ((counter <= T) && index < C.size()) {
            counter += C[index];
            index++;
        }
        if ((counter > T) && (i != A - 1)) {
            counter = 0;
            index--;
        }
    }

    if (counter > T) {
        isPossible = false;
    }

    return isPossible;
}

int paint(int A, int B, std::vector<int> &C) {
    long long sum = 0;

    for (auto &num : C) {
        sum += num;
    }

    long long start = 1;
    long long end = sum;
    long long middle = 0;
    bool possibility = true;

    while (start <= end) {
        middle = (start + end) / 2;

        possibility = isPossible(middle, A, C);

        if (possibility && !isPossible(middle - 1, A, C)) {
            return (int) (((long long) B * middle) % 10000003);
        }

        if (possibility) {
            end = middle - 1;
        } else {
            start = middle + 1;
        }
    }
}

int main() {
    int A = 1;
    int B = 1000000;
    std::vector<int> C = {1000000, 1000000};
    std::cout << paint(A, B, C) << std::endl;
    return 0;
}

