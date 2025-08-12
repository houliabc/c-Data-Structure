#include <iostream>
#include <climits>
#include <vector>

using namespace std;

class MyArray {
private:
    int* data; // 动态分配的数组
    int size;
public:
    // 构造函数：分配内存
    MyArray(int s) {
        size = s;
        data = new int[size]; // 动态分配
        cout << "构造函数：分配了" << size << "个int的内存" << endl;
    }

    // 析构函数：释放内存
    ~MyArray() {
        delete[] data; // 释放动态分配的内存
        cout << "析构函数：释放了内存" << endl;
    }
};

int main() {
    {
        MyArray arr(10); // 创建对象，调用构造函数
    } // 离开作用域，对象被销毁，自动调用析构函数
    return 0;
}