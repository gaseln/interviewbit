#include <vector>
#include <iostream>

int findMedian(std::vector<std::vector<int>> &A) {
    int min = INT_MAX, max = INT_MIN;
    const int N = A.size();
    const int M = A[0].size();
    const int target = (M*N + 1) / 2;
    int row_min = 0;
    int row_max = 0;
    int row_int = 0;
    for (int i = 0; i < N; ++i) {
        min = (min > A[i][0]) ? A[i][0] : min;
        max = (max < A[i][M-1]) ? A[i][M-1] : max;
    }
    //std::cout << min << " " << max << std::endl;
    int intermediate = 0;
    int count_lower;
    int count_upper;
    while (min <= max) {
        count_upper = 0;
        count_lower = 0;
        intermediate = min + (max - min) / 2;
        std::cout << "Intermediate = " << intermediate << std::endl;
        for (int i = 0; i < N; ++i) {
            row_min = 0;
            row_max = M-1;
            if (A[i][0] <= intermediate and A[i][M-1] > intermediate) {
                while (row_min < row_max) {
                    row_int = row_min + (row_max - row_min) / 2;
                    if (A[i][row_int] <= intermediate) {
                        row_min = row_int + 1;
                    } else {
                        row_max = row_int;
                    }
                }
            } else if (A[i][M-1] <= intermediate) {
                row_min = M;
            }
            count_upper += row_min;
            std::cout << "U: Row number: " << i << " num: " << row_min << std::endl;
            //we repeat the same calculations for count_lower
            row_min = 0;
            row_max = M-1;
            if (A[i][0] < intermediate and A[i][M-1] >= intermediate) {
                while (row_min < row_max) {
                    row_int = row_min + (row_max - row_min) / 2;
                    if (A[i][row_int] <= intermediate - 1) {
                        row_min = row_int + 1;
                    } else {
                        row_max = row_int;
                    }
                }
            } else if (A[i][M-1] < intermediate) {
                row_min = M;
            }
            count_lower += row_min;
            std::cout << "L: Row number: " << i << " num: " << row_min << std::endl;
        }
        if ((count_upper >= target) && (count_lower < target)) {
            std::cout << "RESULT: " << intermediate <<std::endl;
            return intermediate;
        } else if (count_upper < target) {
            min = intermediate + 1;
        } else {
            max = intermediate - 1;
        }
    }
    std::cout << "RESULT: FAIL";
    return 0;
}

int main() {
    //std::vector<std::vector<int>> A = {{1}, {1}, {2}, {2}, {2}, {4}, {5}};
    std::vector<std::vector<int>> A = {{1, 3, 5}, {2, 6, 9}, {3, 6, 9}};
    findMedian(A);
    return 0;
}
