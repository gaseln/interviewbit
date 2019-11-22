// Min Stack
#include <iostream>
#include <vector>
#include <set>

std::stack<int> s1;
std::stack<int> s2;

MinStack::MinStack() {
    while (!s1.empty()) s1.pop();
    while (!s2.empty()) s2.pop();
}

void MinStack::push(int x) {
    s1.push(x);
    if (s2.empty() || !s2.empty() && s2.top() >= x) {
        s2.push(x);
    }
}

void MinStack::pop() {
    if (!s1.empty()) {
        auto el = s1.top();
        s1.pop();
        if (el == s2.top()) {
            s2.pop();
        }
    }
}

int MinStack::top() {
    return (s1.empty()) ? -1 : s1.top();
}

int MinStack::getMin() {
    return (s2.empty()) ? -1 : s2.top();
}

int main() {
    auto ms = MinStack();
}