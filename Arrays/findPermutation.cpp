#include <iostream>
#include <vector>
#include <string>

std::vector<int> findPerm(const std::string A, int B) {
    std::vector<int> rng(B);
    std::vector<int> perm(B);
    int l = 0;
    int h = B - 1;
    for (int i = 0; i < B; ++i) {
        rng[i] = i + 1;
    }
    for (int i = 0; i < B - 1; ++i) {
        if (A[i] == 'D') {
            perm[i] = rng[h];
            h--;
        } else {
            perm[i] = rng[l];
            l++;
        }
    }
    perm[B-1] = rng[l];
    return perm;
}

int main() {
    std::string A = "DID";
    int B = 4;
    auto perm = findPerm(A, B);
    for (auto el: perm) {
        std::cout << el << " ";
    }
}
