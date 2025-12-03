#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Interval {
public:
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

int minMeetingRooms(vector<Interval> &intervals) {
    if (intervals.empty()) return 0;
    vector<int> starts, ends;
    for (auto &i : intervals) {
        starts.push_back(i.start);
        ends.push_back(i.end);
    }
    sort(starts.begin(), starts.end());
    sort(ends.begin(), ends.end());
    int i = 0, j = 0, count = 0, maxCount = 0;
    while (i < starts.size()) {
        if (starts[i] < ends[j]) {
            count++;
            maxCount = max(maxCount, count);
            i++;
        } else {
            count--;
            j++;
        }
    }
    return maxCount;
}

int main() {
    vector<Interval> intervals;
    intervals.emplace_back(0, 30);
    intervals.emplace_back(5, 10);
    intervals.emplace_back(15, 20);
    cout << minMeetingRooms(intervals) << endl;
    return 0;
}