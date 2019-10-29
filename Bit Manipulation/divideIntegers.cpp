#include <iostream>

int divide(int a, int b) {

    if (b == 0) {
        return INT_MAX;
    }

    if (a == 0 or b == INT_MIN) {
        return 0;
    }

    if (a == INT_MIN) {
        int int_res = divide(a + abs(b), b);
        if (b < 0) {
            if (int_res == INT_MAX) {
                return INT_MAX;
            } else {
                return int_res + 1;
            }
        } else {
            return int_res - 1;
        }
    }

    if ((a < 0 and b > 0) or (a > 0 and b < 0)) {
        return -divide(-a, b);
    }

    if (a < 0 and b < 0) {
        return divide(-a, -b);
    }

    auto a_ = (unsigned int) a;
    auto b_ = (unsigned int) b;
    unsigned int res = 0;

    auto b_int = b;
    unsigned int pow = 0;

    while (a_ >= b_) {
        while (a_ - b_int > b_int) {
            b_int = b_int << 1;
            pow += 1;
        }
        a_ -= b_int;
        res += 1 << pow;
        pow = 0;
        b_int = b_;
    }


    return res;
}

int main() {
    std::cout << divide(-10, 2) << std::endl;
    return 0;
}