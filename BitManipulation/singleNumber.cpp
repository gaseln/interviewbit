#include <iostream>
#include <vector>

int singleNumber(const std::vector<int>& A) {
    int x = 0;
    for (auto num : A) {
        x = x^num;
    }
    return x;
}

int main(){
    std::cout << singleNumber({1, 2, 2, 3, 1}) << std::endl;
    return 0;
}