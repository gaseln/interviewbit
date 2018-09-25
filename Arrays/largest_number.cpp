#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

std::string largestNumber(const std::vector<int>& A) {
    std::vector<std::string> B(A.size());
    std::string result;
    bool zeros_flag = true;
    for (std::size_t i = 0; i < B.size(); ++i) {
        B[i] = std::to_string(A[i]);
        if (A[i] != 0) {
            zeros_flag = false;
        }
    }
    if (zeros_flag) {
        return "0";
    }
    std::sort(B.begin(), B.end(), [](const std::string& a, const std::string& b) {
        std::string a_ = a + b;
        std::string b_ = b + a;
        return (a_ > b_);
    });
    for (const auto& num: B) {
        result += num;
    }
    return result;
}

int main() {
    std::vector<int> A = {3, 30, 34, 302, 303, 5, 9};
    std::cout << std::endl << largestNumber(A) << std::endl;
    return 0;
}