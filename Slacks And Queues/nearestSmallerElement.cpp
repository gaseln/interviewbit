#include <iostream>
#include <vector>
#include <stack>

std::vector<int> prevSmaller(std::vector<int>& A) {
    std::vector<int> res;
    std::stack<int> solver;
    for (auto el : A) {
        while (!solver.empty()) if (solver.top() >= el) solver.pop(); else break;
        res.push_back((solver.empty()) ? -1 : solver.top());
        solver.push(el);
    }

    return res;
}

int main() {
    std::vector<int> A = {3, 2, 1};
    auto B = prevSmaller(A);
    for (auto el : B) {
        std::cout << el << " ";
    }
    return 0;
}