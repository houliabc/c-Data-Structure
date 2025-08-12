#include <iostream>
#include <climits>
#include <vector>
#define mp make_pair

using namespace std;

int main() {
    // 初始化方法一
    pair<int, float> it;
    it.first = 1;
    it.second = 2.0;
    cout << it.first + it.second;

    // 初始化方法二
    pair<int, double> it2 = std::make_pair(3, 4.1);

    // 初始化方法三
    auto it3 = mp(2, 4.2);
    return 0;
}