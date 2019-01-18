#include <vector>

void setZeroes(std::vector<std::vector<int>>& matrix) {
    int number_of_rows = matrix.size();
    int number_of_columns = matrix[0].size();
    int row = 0, column = 0;
    bool first_zero_flag = false;
    for (int i = 0; i < number_of_rows; ++i) {
        for (int j = 0; j < number_of_columns; ++j) {
            if (matrix[i][j] == 0) {
                if (!first_zero_flag) {
                    row = i;
                    column = j;
                    first_zero_flag = true;
                } else {
                    matrix[row][j] = 0;
                    matrix[i][column] = 0;
                }
            }
        }
    }
    if (first_zero_flag) {
        for (int i = 0; i < number_of_rows; ++i) {
            if (i == row) {
                continue;
            }
            if (matrix[i][column] == 0) {
                matrix[i].assign(number_of_columns, 0);
            } else {
                for (int j = 0; j < number_of_columns; ++j) {
                    if (matrix[row][j] == 0) {
                        matrix[i][j] = 0;
                    }
                }
            }
        }
        matrix[row].assign(number_of_columns, 0);
    }
}

