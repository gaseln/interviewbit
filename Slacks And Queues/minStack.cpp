// Min Stack
#include <iostream>
#include <vector>
#include <set>

class MinStack {
public:
    MinStack() {
        stack.clear();
        set_for_mins.clear();
    }
    void push(int x) {
        stack.push_back(x);
        set_for_mins.insert(x);
        current_min = *set_for_mins.begin();
    }

    void pop() {
        if (!stack.empty()) {
            auto element = stack.back();
            stack.pop_back();
            auto it = set_for_mins.find(element);
            set_for_mins.erase(it);
            current_min = (set_for_mins.empty()) ? -1 : *set_for_mins.begin();
        }
    }
    int top() {
        if (!stack.empty()) {
            return stack.back();
        } else {
            return -1;
        }
    }
    int getMin() {
        if (!stack.empty()) {
            return current_min;
        } else {
            return -1;
        }
    }
private:
    std::vector<int> stack;
    std::multiset<int> set_for_mins;
    int current_min = -1;
};

int main() {
    auto ms = MinStack();
}