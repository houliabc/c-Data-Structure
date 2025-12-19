#include <iostream>
#include <vector>
using namespace std;

// 函数名：findCommonElements
// 传入参数：三个递增、无重复元素的vector（A/B/C）
// 返回值：存储三个序列共同元素的vector
vector<int> findCommonElements(const vector<int>& A, const vector<int>& B, const vector<int>& C, int n);

// 主函数（测试用例）
int main() {
    // 测试用例1：用户给出的示例
    vector<int> A = {1, 2, 3};
    vector<int> B = {2, 3, 4};
    vector<int> C = {-1, 0, 2};
    
    // 调用函数找共同元素
    vector<int> result = findCommonElements(A, B, C, A.size());
    
    // 输出结果
    cout << "三个序列的共同元素为：";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    // 可添加更多测试用例
    return 0;
}

vector<int> findCommonElements(const vector<int>& A, const vector<int>& B, const vector<int>& C, int n) {
    vector<int> common;
    int i = 0, j = 0, k = 0;
    while (i < n && j < n && k < n) {
        if (A[i] == B[j] && B[j] == C[k]) {
            printf("%d\n", A[i]);
            i++; j++; k++;
        }
        else {
            int maxValue = max(A[i], max(B[j], C[k]));
            if (A[i] < maxValue) i++;
            if (B[j] < maxValue) j++;
            if (C[k] < maxValue) k++;
        }
    }
    
    return common;
}