#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int lastStoneWeight(vector<int>& stones) {
    priority_queue<int> pq(stones.begin(), stones.end());
    while (pq.size() >= 2) {
        int y = pq.top();
        pq.pop();
        int x = pq.top();
        pq.pop();
        if (y != x) {
            pq.push(y - x);
        }
    }
    return pq.empty() ? 0 : pq.top();
}

int main() {
    vector<int> stones = {2, 7, 4, 1, 8, 1};
    cout << lastStoneWeight(stones) << endl;
    return 0;
}