#include <iostream>
#include <climits>
#include <vector>

using namespace std;

int main() {
    vector<int> vec = {1, 2, 3};
    for(auto i = vec.begin(); i != vec.end(); i++) {
        printf("%d\t", *i);
    }
    return 0;
}