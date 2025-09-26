#include <iostream>
#include <climits>
#include <vector>

using namespace std;

int main() {
    vector<int> vec = {1, 2, 3};
    for (auto i = vec.rbegin(); i != vec.rend(); i++) {
        printf("%d ", *i);  // 要用解引用符来对迭代器解
    }
    return 0;
}