#include <iostream>
#include <unordered_map>
#include <string>
#include <tuple>

std::string fractionToDecimal(int numerator_, int denominator_) {
    signed long long numerator = numerator_;
    signed long long denominator = denominator_;
    std::string res;
    auto div = (long long)(numerator / denominator);

    if (div == 0 && ((numerator > 0 && denominator < 0) || (numerator < 0 && denominator > 0))) {
        res += '-';
    }

    res += std::to_string(div);

    long long remainder = abs(numerator % denominator);
    if (!remainder) return res;

    res += '.';

    int point_ind = res.length();

    std::unordered_map<int, int> remainder_to_ind;
    int index = 0;
    while (remainder) {

        if (remainder_to_ind.find(remainder) != remainder_to_ind.end()) {
            res.insert(point_ind + remainder_to_ind[remainder], "(");
            res += ")";
            return res;
        }

        remainder_to_ind[remainder] = index;
        ++index;

        remainder *= 10;
        div = remainder / denominator;
        res += std::to_string(abs(div));
        remainder = abs(remainder % denominator);
    }

    return res;
}

int main() {
    int numerator = -1;
    int denominator = INT_MIN;
    std::cout << fractionToDecimal(numerator, denominator);
}