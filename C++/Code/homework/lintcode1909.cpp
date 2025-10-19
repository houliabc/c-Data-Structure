#include <vector>
#include <climits>
#include <iostream>
using namespace std;

class Solution {
private:
    int maxScore;
    vector<int> bestAssign;
    vector<int> currAssign;
    vector<bool> driverUsed;

    void backtrack(int orderIdx, const vector<vector<int>>& score) {
        if (orderIdx == score.size()) {
            int total = 0;
            for (int i = 0; i < score.size(); ++i) {
                total += score[i][currAssign[i]];
            }
            if (total > maxScore) {
                maxScore = total;
                bestAssign = currAssign;
            }
            return;
        }
        for (int driver = 0; driver < score.size(); ++driver) {
            if (!driverUsed[driver]) {
                driverUsed[driver] = true;
                currAssign[orderIdx] = driver;
                backtrack(orderIdx + 1, score);
                driverUsed[driver] = false;
            }
        }
    }

public:
    vector<int> orderAllocation(vector<vector<int>>& score) {
        int n = score.size();
        maxScore = INT_MIN;
        bestAssign.resize(n);
        currAssign.resize(n);
        driverUsed.resize(n, false);
        backtrack(0, score);
        return bestAssign;
    }
};

int main() {
    vector<vector<int>> score = {
        {1, 2, 4},
        {7, 11, 16},
        {37, 29, 22}
    };
    Solution sol;
    vector<int> res = sol.orderAllocation(score);

    cout << "派单结果：";
    for (int driver : res) {
        cout << driver << " ";
    }
    cout << endl;

    int total = 0;
    for (int i = 0; i < score.size(); ++i) {
        total += score[i][res[i]];
    }
    cout << "最大总得分：" << total << endl;

    return 0;
}