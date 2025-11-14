#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> results;

void dfs(int pos, int value, string expr, int last, const vector<int>& digits) {
    if (pos == digits.size()) {
        if (value == 100) {
            results.push_back(expr);
        }
        return;
    }
    // 插入 '+'
    dfs(pos + 1, value + digits[pos], expr + "+" + to_string(digits[pos]), digits[pos], digits);
    // 插入 '-'
    dfs(pos + 1, value - digits[pos], expr + "-" + to_string(digits[pos]), -digits[pos], digits);
    // 不插入，合并数字
    int new_last = last * 10 + digits[pos];
    string new_expr = expr;
    string last_str = to_string(abs(last));
    size_t last_pos = new_expr.find_last_of(last_str);
    if (last_pos != string::npos) {
        string new_last_str = to_string(abs(new_last));
        if (last < 0) {
            new_expr = new_expr.substr(0, last_pos) + "-" + new_last_str;
        } else {
            new_expr.replace(last_pos, last_str.size(), new_last_str);
        }
    }
    int new_value = value - last + new_last;
    dfs(pos + 1, new_value, new_expr, new_last, digits);
}

vector<string> find100Expressions() {
    vector<int> digits = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    results.clear();
    dfs(1, 1, "1", 1, digits);
    return results;
}

int main() {
    vector<string> exprs = find100Expressions();
    for (const string& expr : exprs) {
        cout << expr << "=100" << endl;
    }
    cout << "共有 " << exprs.size() << " 种解法" << endl;
    return 0;
}