#include <vector>
#include <algorithm>
#include <iostream>
//Haven't succeeded to solve
int maxSpecialProduct(std::vector<int> &A) {
    int n = A.size();
    long long max = 0;
    std::vector<int> stack, LSV(n), RSV(n);
    for (int i = 0; i < n; ++i) {
        while(!stack.empty()) {
            if (A[stack.back()] > A[i]) break;
            stack.pop_back();
        }
        LSV[i] = (stack.empty()) ? 0 : stack.back();
        stack.push_back(i);
    }
    stack.clear();
    for (int i = n - 1; i >= 0; --i) {
        while(!stack.empty()) {
            if (A[stack.back()] > A[i]) break;
            stack.pop_back();
        }
        RSV[i] = (stack.empty()) ? 0 : stack.back();
        stack.push_back(i);
    }
    for (int i = 0; i < n; ++i) {
        max = std::max(max, LSV[i] *1LL* RSV[i]);
    }
    return (int)(max%1000000007);
}

int main() {
    std::vector<int> A = {5, 9, 6, 8, 6, 4, 6, 9, 5, 4, 9};
    std::cout <<maxSpecialProduct(A) << std::endl;
    return 0;
}