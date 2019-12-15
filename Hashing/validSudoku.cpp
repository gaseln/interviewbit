// Valid Sudoku
#include <iostream>
#include <vector>

bool checkAndZero(std::vector<char>& hash) {
    for (auto& el : hash) {
        if (el > 1) {return false;} else {el = 0;}
    }

    return true;
}

int isValidSudoku(const std::vector<std::string>& board) {

    std::vector<char> hash(9);

    for (const auto& line : board) {
        for (const auto& sym : line) {
            if (sym != '.') {
                hash[sym - '1'] += 1;
            }
        }

        if (!checkAndZero(hash)) return 0;
    }

    for (unsigned char i = 0; i < 9; ++i) {
        for (unsigned char j = 0; j < 9; ++j) {
            if (board[j][i] != '.') {
                hash[board[j][i] - '1'] += 1;
            }
        }

        if (!checkAndZero(hash)) return 0;
    }

    for (unsigned char col_group = 0; col_group < 3; ++col_group) {
        for (unsigned char row_group = 0; row_group < 3; ++row_group) {
            for (unsigned char col_it = 0; col_it < 3; ++col_it) {
                for (unsigned char row_it = 0; row_it < 3; ++row_it) {
                    if (board[3 * col_group + col_it][3 * row_group + row_it] != '.') {
                        hash[board[3 * col_group + col_it][3 * row_group + row_it]  - '1'] += 1;
                    }
                }
            }

            if (!checkAndZero(hash)) return 0;
        }
    }

    return 1;
}