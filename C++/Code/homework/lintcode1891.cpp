#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> arr[i][j];
        }
    }
    int full = (1 << n) - 1;
    vector<vector<int>> dp(1 << n, vector<int>(n, INT_MAX));
    dp[1 << 0][0] = 0;
    for (int state = 0; state < (1 << n); ++state) {
        for (int u = 0; u < n; ++u) {
            if (dp[state][u] == INT_MAX) continue;
            for (int v = 0; v < n; ++v) {
                if (!(state & (1 << v))) {
                    int new_state = state | (1 << v);
                    dp[new_state][v] = min(dp[new_state][v], dp[state][u] + arr[u][v]);
                }
            }
        }
    }
    int ans = INT_MAX;
    for (int u = 0; u < n; ++u) {
        if (dp[full][u] != INT_MAX) {
            ans = min(ans, dp[full][u] + arr[u][0]);
        }
    }
    cout << ans << endl;
    return 0;
}