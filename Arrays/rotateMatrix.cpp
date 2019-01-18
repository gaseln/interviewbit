#include <iostream>
#include <vector>

void rotateMatrix(std::vector<std::vector<int>>& matrix) {
    size_t n = matrix.size();
    std::vector<int> group(4);
    for (int i = 0; i < (int)n / 2; ++i) {
        for (int j = 0; j < (int) (n + 1)/2; ++j) {
            group = {matrix[j][i], matrix[i][n-j-1], matrix[n-j-1][n-i-1], matrix[n-i-1][j]};
            matrix[j][i] = group[3];
            matrix[i][n-j-1] = group[0];
            matrix[n-j-1][n-i-1] = group[1];
            matrix[n-i-1][j] = group[2];
        }
    }
}


int main() {
    std::vector<std::vector<int>> matrix = {{1, 2, 3, 4},
                                            {5, 6, 7, 8},
                                            {9, 10, 11, 12},
                                            {13, 14,15, 16}};
    rotateMatrix(matrix);
    for (auto line: matrix) {
        for (auto el : line) {
            std::cout << el << " ";
        }
        std::cout << "\n";
    }
}