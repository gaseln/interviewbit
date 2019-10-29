#include <iostream>

int numSetBits(unsigned int x) {
    return __builtin_popcount(x);
}

int main() {
    std::cout << numSetBits(11);
    return 0;
}