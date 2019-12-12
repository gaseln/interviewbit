// Sudoku
#include <iostream>
#include <vector>

bool isSuitable(std::vector<std::vector<char>>& board, char& line, char& col) {
    for (auto& el : board[line]) {
        if (&el != &board[line][col] && el == board[line][col]) {
            return false;
        }
    }


    for (auto& line_ : board) {
        if (&line_ != &board[line] && line_[col] == board[line][col]) {
            return false;
        }
    }

    int start_line = (line / 3) * 3;
    int start_col = (col / 3) * 3;

    for (int i = start_line; i < start_line + 3; ++i) {
        for (int j = start_col; j < start_col + 3; ++j) {

            if (i == line && j == col) {
                continue;
            }

            if (board[line][col] == board[i][j]) {
                return false;
            }
        }
    }

    return true;
}

bool helper(std::vector<std::vector<char>>& board, std::vector<char>& lines, std::vector<char>& columns, int& next) {

    if (next >= lines.size()) {
        return true;
    }


    for (char variant = '1'; variant <= '9'; ++variant) {
        board[lines[next]][columns[next]] = variant;
        if (isSuitable(board, lines[next], columns[next])) {
            next++;
            if (helper(board, lines, columns, next)) {
                return true;
            }
            next--;
        }
    }

    board[lines[next]][columns[next]] = '.';

    return false;
}


void solveSudoku(std::vector<std::vector<char>>& board) {
    std::vector<char> lines, columns;
    for (char line = 0; line < 9; ++line) {
        for (char col = 0; col < 9; ++col) {
            if (board[line][col] == '.') {
                lines.push_back(line);
                columns.push_back(col);
            }
        }
    }

    int next = 0;
    helper(board, lines, columns, next);
}

int main() {
    std::vector<std::vector<char>> board = {{'5','3','.','.','7','.','.','.','.'},
                                            {'6','.','.','1','9','5','.','.','.'},
                                            {'.','9','8','.','.','.','.','6','.'},
                                            {'8','.','.','.','6','.','.','.','3'},
                                            {'4','.','.','8','.','3','.','.','1'},
                                            {'7','.','.','.','2','.','.','.','6'},
                                            {'.','6','.','.','.','.','2','8','.'},
                                            {'.','.','.','4','1','9','.','.','5'},
                                            {'.','.','.','.','8','.','.','7','9'}};
    solveSudoku(board);
    for (auto& line : board) {
        for (auto& sym : line) {
            std::cout << sym << " ";
        }
        std::cout << std::endl;
    }
}