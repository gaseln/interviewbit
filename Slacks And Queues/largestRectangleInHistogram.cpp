// Largest Rectangle In Histogram
#include <iostream>
#include <vector>
#include <tuple>
#include <stack>

int largestRectangleArea(std::vector<int>& heights) {
    int max = 0, last_pos = 0;
    heights.push_back(0);
    std::stack<std::pair<int, int>> left_positions;
    for (int i = 0; i < heights.size(); ++i) {
        if (left_positions.empty() || left_positions.top().first < heights[i]) {
            left_positions.push(std::make_pair(heights[i], i));
        } else {
            do {
                last_pos = left_positions.top().second;
                max = std::max(max, left_positions.top().first * (i - last_pos));
                left_positions.pop();
            } while (!left_positions.empty() && left_positions.top().first >= heights[i]);
            left_positions.push(std::make_pair(heights[i], last_pos));
        }
    }
    return max;
}

int main() {
    std::vector<int> heights = {2,1,5,6,2,3};
    std::cout << largestRectangleArea(heights);
    return 0;
}