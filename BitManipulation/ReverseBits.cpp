#include <iostream>

unsigned int reverse(unsigned int A) {
    unsigned int n = A;
    unsigned int x=UINT_MAX;
    unsigned int res=0;
    while (n!=0) {
        x = (n^(n-1)) + 1;
        res += (x != 0) ? UINT_MAX/x + 1 : 1;
        n = n & (n-1);
    }
    return res;
}

int main() {
    std::cout << std::bitset<32> (reverse(4294967295)) << std::endl;
    return 0;
}