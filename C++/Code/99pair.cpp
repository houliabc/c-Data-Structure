#include <iostream>
#include <climits>
#include <vector>
#define mp make_pair
#define MAXN 3
#include <algorithm>

using namespace std;

int main() {
    // 初始化方法一
    pair<int, double> it;
    it.first = 1;
    it.second = 2.0;
    cout << it.first + it.second << endl;

    // 初始化方法二
    pair<int, double> it2 = std::make_pair(3, 4.1);

    // 初始化方法三
    pair<int, float> it3 = {1, 'a'};

    // 比较（直接对pair类型比较，而不是里面的成员）
    if (it < it2) cout << "it2 win" << endl;


    // `pair` 可以轻松实现离散化。
    // a为原始数据
    pair<int, int> a[MAXN];
    // ai为离散化后的数据
    int ai[MAXN];
    for (int i = 0; i < MAXN; i++) {
    // first为原始数据的值，second为原始数据的位置（下标，从0开始）
    scanf("%d", &a[i].first);
    a[i].second = i;
    }

    // 排序
    sort(a, a + MAXN);  // 这里用到了数组地址的特性，如果是容器，使用的方式是 xx.begin()

    for (int i = 0; i < MAXN; i++) {
    // 将该值的排名（从0开始）赋给该值原本所在的位置
        ai[a[i].second] = i;
    }

    for (auto i: ai) cout << i << ',';
    return 0;
}