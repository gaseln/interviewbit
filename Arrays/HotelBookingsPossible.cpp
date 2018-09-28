#include <vector>
#include <iostream>
#include <algorithm>

bool hotel(std::vector<int> &arrive, std::vector<int> &depart, int K) {
    std::sort(arrive.begin(), arrive.end());
    std::sort(depart.begin(), depart.end());
    auto arr_it = arrive.begin();
    auto dep_it = depart.begin();
    int max = 0, current_num = 0;
    while (arr_it != arrive.end() and dep_it != depart.end()) {
        if (arr_it == arrive.end()) {
            ++dep_it;
            current_num--;
        }
        if (*arr_it > *dep_it) {
            ++dep_it;
            current_num--;
        } else if (*arr_it < *dep_it) {
            ++arr_it;
            current_num++;
            if (current_num > max) {
                max = current_num;
            }
        } else {
            ++arr_it;
            ++dep_it;
        }
    }
    return (K >= max);
}

int main() {
    std::vector<int> arrive = {1, 3, 5};
    std::vector<int> depart = {2, 6, 8};
    std::cout << hotel(arrive, depart, 1) << std::endl;
    return 0;
}