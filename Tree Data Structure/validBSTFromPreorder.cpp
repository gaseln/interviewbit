#include <iostream>
#include <vector>
#include <stack>

int solve(std::vector<int> &A) {
    std::stack<int> sorting_stack;
    int lower_bound = INT_MIN;
    for (auto& el: A) {
        if (el < lower_bound) {
            return 0;
        }
        while (!sorting_stack.empty() && el > sorting_stack.top()) {
            lower_bound = sorting_stack.top();
            sorting_stack.pop();
        }

        sorting_stack.push(el);
    }
    return 1;
}