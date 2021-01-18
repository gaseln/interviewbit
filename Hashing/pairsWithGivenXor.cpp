#include <iostream>
#include <vector>
#include <unordered_map>

int solve(std::vector<int>& A, int B) {
    std::unordered_map<int, int> As_count;
    for (auto& el : A) {
        As_count[el] += 1;
    }
    int result = 0, tmp;
    for (auto& el : A) {
        tmp = el xor B;
        if (As_count.find(tmp) != As_count.end()) {
            result += As_count[tmp];
            if (B == 0) {result--;}
        }
    }

    result /= 2;
    return result;
}

int main() {
    std::vector<int> A = {3, 6, 8, 10, 15, 50};
    int B = 5;
    std::cout << solve(A, B);
}