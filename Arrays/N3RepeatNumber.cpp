#include <iostream>
#include <vector>

//Solution is based on Moore's Voting Algorithm

int repeatNumber(std::vector<int> arr) {
    int n = arr.size();
    int first, second;
    first = second = INT_MAX;
    int count1, count2;
    count1 = count2 = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] == first) {
            count1++;
        } else if (arr[i] == second) {
            count2++;
        } else if (count1 == 0) {
            first = arr[i];
            count1 = 1;
        } else if (count2 == 0) {
            second = arr[i];
            count2 = 1;
        } else {
            count1--;
            count2--;
        }
    }
    count1 = 0;
    count2 = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == first) {
            count1++;
        } else if (arr[i] == second) {
            count2++;
        }
    }

    if (count1 > n / 3)
        return first;

    if (count2 > n / 3)
        return second;

    return -1;
}

int main() {
    std::vector<int> ex = {10, 10, 20, 30, 10, 10 };
    std::cout << repeatNumber(ex) << std::endl;
    return 0;
}