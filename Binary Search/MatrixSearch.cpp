#include <vector>
#include <iostream>

int searchMatrix(std::vector<std::vector<int> > &A, int B) {
    int m = (int) A.size() - 1;
    int n = (int) A[0].size() - 1;

    int min = 0;
    int max = m;
    int intermediate;

    if (A[0][0] <= B and (A[m][0] >= B)) {
        while (min < max) {
            intermediate = min + (max - min + 1) / 2;
            if (A[intermediate][0] <= B) {
                min = intermediate;
            } else {
                max = intermediate - 1;
            }
        }
    } else if (A[0][0] > B) {
        return 0;
    }

    int row = max;

    min = 0; max = n;

    while (min < max) {
        intermediate = min + (max - min + 1) / 2;
        if (A[row][intermediate] <= B) {
            min = intermediate;
        } else {
            max = intermediate - 1;
        }
    }

    return (A[row][min] == B);

}

int main() {
    std::vector<std::vector<int>> A = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50}};

    std::cout << searchMatrix(A, 4) << std::endl;
    return 0;
}
