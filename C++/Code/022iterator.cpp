#include <iostream>
#include <climits>
#include <set>

using namespace std;

int main() {
    // C++98/03 写法（无 auto）
    set<int> st = {1, 2};
    for (set<int>::iterator it = st.begin(); it != st.end(); ++it)
        cout << *it << endl;
    // c11可用auto了
    for (auto it = st.begin(); it != st.end(); ++it)
        cout << *it << endl;
    return 0;
}