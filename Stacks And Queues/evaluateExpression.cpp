// Evaluate Expression
#include <iostream>
#include <vector>
#include <string>
#include <set>

int operationRes(int a, int b, std::string sign) {
    if (sign == "+") {
        return a + b;
    }

    if (sign == "-") {
        return a - b;
    }

    if (sign == "*") {
        return a * b;
    }

    if (sign == "/") {
        return a / b;
    }

    return 0; // never reached
}

int evalRPN(std::vector<std::string>& tokens) {
    std::set<std::string> signs = {"+", "-", "*", "/"};
    std::vector<std::string> stack;
    int l_ind;
    for (int i = (int) tokens.size() - 1; i >=0; --i) {
        stack.push_back(tokens[i]);
        l_ind = (int) stack.size() - 1;
        while (l_ind > 1 && signs.find(stack[l_ind]) == signs.end() && signs.find(stack[l_ind - 1]) == signs.end()) {
            int a = std::stoi(stack[l_ind]);
            int b = std::stoi(stack[l_ind - 1]);
            auto sign = stack[l_ind - 2];
            stack.pop_back();
            stack.pop_back();
            stack.pop_back();
            auto res = operationRes(a, b, sign);
            stack.push_back(std::to_string(res));
            l_ind = (int) stack.size() - 1;
        }
    }

    return std::stoi(stack.back());
}

int main() {
    std::vector<std::string> tokens = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    std::cout << evalRPN(tokens);
    return 0;
}