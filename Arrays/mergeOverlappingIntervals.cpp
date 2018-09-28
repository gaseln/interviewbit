#include <vector>
//this problem is similar to the problem "Merge Intervals"
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};


std::vector<Interval> merge(std::vector<Interval>& intervals) {
    if (intervals.size() < 1) {
        return {};
    }
    std::vector<int> begins(intervals.size());
    std::vector<int> ends(intervals.size());
    std::vector<Interval> res;
    for (int i = 0; i < intervals.size(); ++i) {
        begins[i] = intervals[i].start;
        ends[i] = intervals[i].end;
    }
    std::sort(begins.begin(), begins.end());
    std::sort(ends.begin(), ends.end());
    int index = 0, prev_index = 0;
    while (index < begins.size() - 1) {
        if (begins[index + 1] > ends[index]) {
            res.emplace_back(begins[prev_index], ends[index]);
            ++index;
            prev_index = index;
        } else {
            ++index;
        }
    }
    res.emplace_back(begins[prev_index], ends[index]);
    return res;
}
