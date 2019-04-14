#include <iostream>

int pow(int x, int n, int p) {
    if (x < 0) {
        if (n % 2 == 1) {
            return p - pow(-x, n, p);
        } else {
            return pow(-x, n, p);
        }
    }
    if (n==0) {
        int res = (x==0) ? 0 : 1;
        return res;
    } else if (n % 2 == 1) {
        auto int_res = (long long) pow(x, n/2, p);
        long long int_res2 = int_res * int_res % p;
        long long res = int_res2 * (x % p) % p;
        return (int) res;
    } else {
        auto int_res = (long long) pow(x, n/2, p);
        long long res = int_res * int_res % p;
        return (int) res ;
    }
}

int main() {
    std::cout << pow(-1, 1, 20);
    return 0;
}