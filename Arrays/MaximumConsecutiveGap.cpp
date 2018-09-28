#include <vector>
#include <climits>
#include <cmath>
#include <iostream>

int maximumGap(const std::vector<int> &A) {
    int n = A.size();
    if (n < 2) {
        return 0;
    }
    int minVal = *std::min_element(A.begin(), A.end());
    int maxVal = *std::max_element(A.begin(), A.end());
    std::vector<int> mins(n - 1, INT_MAX);
    std::vector<int> maxs(n - 1, INT_MIN);
    float average_gap = (float)(maxVal - minVal) / (n - 1);
    for (const auto& el : A) {
        if (el == maxVal) {
            continue;
        }
        int index = (int)floor(float(el - minVal) / average_gap);
        if (mins[index] == INT_MAX) {
            mins[index] = el;
        } else {
            mins[index] = std::min(mins[index], el);
        }
        if (maxs[index] == INT_MIN) {
            maxs[index] = el;
        } else {
            maxs[index] = std::max(maxs[index], el);
        }
    }
    int max_gap = 0;
    int prevVal = minVal;
    for (int i = 0; i < n - 1; ++i) {
        if (maxs[i] == INT_MIN) {
            continue;
        }
        max_gap = std::max(max_gap, mins[i] - prevVal);
        prevVal = maxs[i];
    }
    max_gap = std::max(max_gap, maxVal - prevVal);
    return max_gap;
}

int main() {
    std::vector<int> A = {};
    std::cout << maximumGap(A);
    return 0;
}
