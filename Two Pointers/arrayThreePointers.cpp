//Array 3 Pointers
#include <iostream>
#include <vector>

int abs_max(int a, int b, int c) {
    return std::max(abs(a - b), std::max(abs(b - c), abs(c - a)));
}

bool updateInd(int& ind_a, int& ind_b, int& ind_c, const std::vector<int>& A, const std::vector<int>& B, const std::vector<int>& C) {
    if (ind_a != A.size() && A[ind_a] <=  std::min(B[ind_b], C[ind_c])) {
        ++ind_a;
        return true;
    }

    return false;
}

int minimize(const std::vector<int>& A, const std::vector<int>& B, const std::vector<int>& C) {
    int ind_a = 0, ind_b = 0, ind_c = 0;
    int min = INT_MAX;
    while (ind_a != A.size() && ind_b != B.size() && ind_c != C.size()) {

        min = std::min(min, abs_max(A[ind_a], B[ind_b], C[ind_c]));
        if (updateInd(ind_a, ind_b, ind_c, A, B, C)) continue;
        if (updateInd(ind_b, ind_a, ind_c, B, A, C)) continue;
        if (updateInd(ind_c, ind_b, ind_a, C, B, A)) continue;

    }

    return min;
}

int main() {
    std::vector<int> A = {1, 4, 10};
    std::vector<int> B = {2, 15, 20};
    std::vector<int> C = {10, 12};
    std::cout << minimize(A, B, C);
    return 0;
}