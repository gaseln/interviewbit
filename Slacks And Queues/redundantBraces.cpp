//Redundant braces
#include <iostream>
#include <stack>

int braces(std::string expresssion) {
    std::stack<int> exp;
    bool flag = false;
    for (auto el : expresssion) {
        if (el == '(') {
            exp.push(1);
            exp.push(1);
            flag = true;
        } else if (el == ')') {

            if (flag) {
                return 1;
            }

            exp.pop();
            flag = false;
        } else if (el == '+' || el == '-' || el == '*' || el == '/') {
            if (!exp.empty()) exp.pop();
            flag = false;
        }
    }

    return (int) (!exp.empty());
}

int main() {
    std::string A = "(a*b)+(b*c)";
    std::cout << braces(A);
    return 0;
}