#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Stud {
    int no;
    string name;

    // 结构体（类似于java 的类）的构造函数
    Stud(int no1, string name1) {
        no = no1;
        name = name1;
    }

    // 方法一：重载<运算符来实现递减排序
    bool operator < (const Stud &s) const {
        return no > s.no;
    }
};

// 方法二：定义关系函数（）
struct Cmp {
    bool operator()(const Stud &s, const Stud &t) const {
        return s.name < t.name;
    }
};


int main() {
    vector<int> vec = {1, 2, 3};
    // sort默认是用less递增排序，这里是递减排序
    sort(vec.begin(), vec.end(), greater<int>());
    for (auto i: vec) {
        printf("%d ", i);  // 要用解引用符来对迭代器解
    }

    // 重载递减排序
    Stud a[] = {Stud(2, "mary"), Stud(4, "jack"), Stud(1, "smile")};
    vector<Stud> vec2(a, a + sizeof(a) / sizeof(a[0]));
    // 这里sort的第三个参数已经被重载为新的了
    sort(vec2.begin(), vec2.end());
    for (auto i: vec2)
        printf("%d ", i.no);   // 这里结构体引用成员用“.”
    sort(vec2.begin(), vec2.end());
    

    // 方法二：自定义排序，这里自定义函数注意要括号（）
    sort(vec2.begin(), vec2.end(), Cmp());
    for (auto i: vec2)
        printf("%d ", i.no);   // 这里结构体引用成员用“.”

    // 方法三：用lambda来自定义排序（这里是递减），就不用单独写一个函数
    sort(vec2.begin(), vec2.end(), [](Stud &a, Stud &b) -> bool { return a.no > b.no; });
    for (auto i: vec2)
        printf("%d ", i.no);   // 这里结构体引用成员用“.”
    return 0;
}