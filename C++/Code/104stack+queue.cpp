#include <iostream>
#include <climits>
#include <vector>
#include <queue>
#include <stack>
#include <list>

using namespace std;

int main() {
    std::stack<int, std::vector<int>> third;  // 使用vector为底层容器的栈
    std::queue<int, std::list<int>> third2;  // 使用list为底层容器的队列

    // 默认的情况下
    stack<int> st;
    queue<int> de;
    return 0;
}