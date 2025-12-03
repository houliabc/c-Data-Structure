#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct Job {
    int d, w;
    Job(int d, int w) : d(d), w(w) {}
};

bool compare(const Job& a, const Job& b) {
    return a.w > b.w;
}

int minPenalty(vector<Job>& jobs) {
    sort(jobs.begin(), jobs.end(), compare);
    int maxD = 0;
    for (auto& job : jobs) {
        if (job.d > maxD) maxD = job.d;
    }
    vector<bool> slot(maxD + 1, false);
    int penalty = 0;
    for (auto& job : jobs) {
        int t = job.d;
        while (t > 0 && slot[t]) t--;
        if (t == 0) {
            penalty += job.w;
        } else {
            slot[t] = true;
        }
    }
    return penalty;
}

int main() {
    vector<Job> jobs = {{4,70}, {2,60}, {4,50}, {3,40}, {1,30}, {4,20}, {6,10}};
    cout << minPenalty(jobs) << endl;
    return 0;
}