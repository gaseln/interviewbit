#include <vector>
#include <iostream>

std::vector<int> subUnsort(std::vector<int> &A) {
    int begin = 0, end = A.size() - 1;
    int min = A[0], max = A[A.size() - 1];
    bool ascent_flag = false, descent_flag = false;
    bool begin_flag = false, end_flag = false;
    for (int i = 1; i < A.size(); ++i) {
        if ((A[i] < A[i - 1]) and !ascent_flag) {
            ascent_flag = true;
            begin = i;
            min = A[i-1];
        }
        if (A[i] < min) {
            begin_flag = true;
            while (begin > 0) {
                begin--;
                if (A[begin] <= A[i]) {
                    begin_flag = false;
                    min = A[begin];
                    break;
                }
            }
        }
    }
    if (!ascent_flag) {
        return {-1};
    }
    if (!begin_flag) {
        ++begin;
    }
    for (int i = A.size() - 1; i > begin; --i) {
        if ((A[i] < A[i - 1]) and !descent_flag) {
            descent_flag = true;
            end = i;
            max = A[i];
        }
        if (A[i - 1] > max) {
            end_flag = true;
            while (end < A.size() - 1) {
                end++;
                if (A[end] >= A[i-1]) {
                    end_flag = false;
                    max = A[end];
                    break;
                }
            }
        }
    }
    if (!end_flag) {
        --end;
    }
    return {begin, end};
}

int main() {
    std::vector<int> A = {3, 3, 4, 5, 5, 9, 11, 13, 14, 15, 15, 16, 15, 20, 16};
    auto B = subUnsort(A);
    for (const auto& el: B) {
        std::cout << el << " ";
    }
    return 0;
}