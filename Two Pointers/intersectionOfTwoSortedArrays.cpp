#include <iostream>
#include <vector>

std::vector<int> intersect(const std::vector<int>& A, const std::vector<int>& B){
    std::vector<int> res;
    auto it_a = A.begin();
    auto it_b = B.begin();
    while (true) {
        if (*it_a == *it_b) {
            res.push_back(*it_a);
            it_a++;
            it_b++;
        } else if (*it_a < *it_b) {
            it_a++;
        } else {
            it_b++;
        }

        if (it_a == A.end()) {
            break;
        }

        if (it_b == B.end()) {
            break;
        }
    }

    return res;
}

int main() {
    std::vector<int> A = {98, 100, 101};
    std::vector<int> B = {94, 94, 98};
    auto res = intersect(A, B);
    for (auto el : res) {
        std::cout << el << " ";
    };
    return 0;
}