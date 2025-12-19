#include <iostream>
#include <vector>
using namespace std;

// 函数名：leftRotateArray
// 传入参数：
//   arr - 待循环左移的数组（引用传递，支持直接修改原数组）
//   n   - 数组的长度
//   p   - 循环左移的位数（要求 0 < p < n）
// 返回值：void（直接修改原数组，无需返回值）
void leftRotateArray(vector<int>& arr, int n, int p);

// 主函数模板（你可根据需要修改测试用例）
int main() {
    // 示例测试用例（可自行替换/扩展）
    vector<int> arr = {1, 2, 3, 4, 5};
    int n = arr.size();  // 数组长度
    int p = 2;           // 循环左移2位

    // 输出原数组
    cout << "原数组：";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // 调用循环左移函数（实现由你补充）
    leftRotateArray(arr, n, p);

    // 输出左移后的数组
    cout << "循环左移" << p << "位后的数组：";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

void traversal(vector<int>& arr, int begin, int end) {
    while (begin < end) {
        swap(arr[begin++], arr[end--]);
    }
}
void leftRotateArray(vector<int>& arr, int n, int p) {
    // 可以先将整个数组逆置，再将前n-p，后p分别再逆置
    traversal(arr, 0, n - 1);
    traversal(arr, 0, n - p - 1);
    traversal(arr, n - p, n - 1);
}