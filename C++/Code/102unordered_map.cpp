#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n, a, b;
    unordered_map<int, int> hashmap{};  // 类似与python中的字典
    unordered_map<int, string> hashmap2{{1, "apple"}, {2, "ggbond"}}; 

    // 判断hashmap是否为空，返回true或false
    cout << hashmap.empty() << endl;  
    hashmap[1] = 2;  // 初始化一个元素

    if (hashmap.contains(1)) {  // 判断hashmap中是否存在key为1的元素，C++20新特性
        cout << "hashmap[1] = " << hashmap[1] << endl;
    } else {
        cout << "hashmap[1] not found" << endl;
    }
    // 也可以使用find()方法来判断元素是否存在
    auto it = hashmap.find(1);
    if (it != hashmap.end()) {
        cout << "hashmap[1] = " << it->second << endl; // 使用find查找哈希表后访问使用“->”的方式
    } else {
        cout << "hashmap[1] not found" << endl;
    }
    // 还可以用count的方式
    cout << "hashmap[1] count = " << hashmap.count(1) << endl;  

    // 获取指定键对应的值，若不存在会返回默认构造的值（int类型为0，string类型为空字符串）
    cout << hashmap[2] << endl;  // 输出0
    // 输出空字符串
    cout << hashmap2[4] << endl;

    hashmap.erase(1);  // 删除key为1的元素

    cout << hashmap.size() << endl;  

    // 哈希表的三种插入方式
    hashmap.insert({9, 3});  // 使用insert方法插入，如果已存在则不会插入
    hashmap[3] = 4;  // 使用下标操作符插入
    hashmap.emplace(4, 5);  // 哈希表没有emplace_back

    // 遍历hashmap
    for (auto &p: hashmap) {
        cout << p.first << ':' << p.second << endl;
    }

    // 清空哈希表，也可以初始化哈希表的方式
    hashmap.clear();  

    return 0;
}