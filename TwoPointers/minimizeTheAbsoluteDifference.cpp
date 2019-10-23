//Minimize the absolute difference
#include <iostream>
#include <vector>

int min(int a, int b, int c) {
    return std::min(a, std::min(b, c));
}

int max(int a, int b, int c) {
    return std::max(a, std::max(b, c));
}

int solve(std::vector<int>& A, std::vector<int>& B, std::vector<int>& C) {
    auto it_a = A.begin();
    auto it_b = B.begin();
    auto it_c = C.begin();
    int res = INT_MAX;

    while (!(it_a == A.end() || it_b == B.end() || it_c == C.end())) {
        res = std::min(res, max(*it_a, *it_b, *it_c) - min(*it_a, *it_b, *it_c));

        if (*it_a <= std::min(*it_b, *it_c)) {
            it_a++;
            continue;
        }

        if (*it_b <= std::min(*it_a, *it_c)) {
            it_b++;
            continue;
        }

        it_c++;
    }

    return res;
}

int main() {
    std::vector<int> A = {1, 4, 5, 8, 10};
    std::vector<int> B = {6, 9, 15};
    std::vector<int> C = {2, 3, 6, 6};
    std::cout << solve(A, B, C);
    return 0;
}