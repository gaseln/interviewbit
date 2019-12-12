// Colourful Number
#include <set>
#include <iostream>

bool helper(std::set<int>& products, int& N, bool& whole_seq_flag) {

    int copy = N, prod = 1;
    while (N) {
        if (N < 10 && !whole_seq_flag) {
            whole_seq_flag = true;
            continue;
        }

        prod *= N % 10;
        if (products.find(prod) == products.end()) {
            products.insert(prod);
        } else {
            return false;
        }
        N /= 10;
    }

    copy /= 10;
    return copy ? helper(products, copy, whole_seq_flag) : true;
}

int colorful(int N) {
    std::set<int> products;
    bool flag = false;
    return helper(products, N, flag);
}

int main() {
    std::cout << colorful(3245);
}

