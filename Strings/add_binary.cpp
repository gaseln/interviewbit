#include <iostream>
#include <string>
#include <algorithm>



std::string addBinary(std::string a, std::string b) {
    if (a.size() > b.size()) {
        return addBinary(b, a);
    }

    int memory = 0, count, a_subs;
    std::string res;

    auto it_a = a.rbegin();
    auto it_b = b.rbegin();

    while (it_b != b.rend()) {
        a_subs = (it_a == a.rend()) ? 0 : (*it_a - '0');
        count = a_subs + (*it_b - '0') + memory;
        res += std::to_string(count % 2);
        memory = (count > 1);
        if (it_a != a.rend())
            it_a++;
        it_b++;
    }

    res += (memory == 1) ? "1" : "";

    std::reverse(res.begin(), res.end());
    return res;
}

int main() {
    std::string a = "1010";
    std::string b = "1011";
    std::cout << addBinary(a, b);
    return 0;
}