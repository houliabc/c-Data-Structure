#include <iostream>
using namespace std;

int plusFunc(int x, int y) {
    return x + y;
}

//c++支持函数重载，函数名相同，参数不同
// 这里的参数不同是指参数类型不同，或者参数个数不同
//如果参数类型不完全不同，则可能报错。需要确保两个函数的参数类型完全不同
// 常见的应用有容器的定义：
// std::priority_queue<TypeName> q;             // 数据类型为 TypeName
// std::priority_queue<TypeName, Container> q;  // 使用 Container 作为底层容器
// std::priority_queue<TypeName, Container, Compare> q;
double plusFunc(double x, double y) {
    return x - y;
}

int main() {
    int myNum1 = plusFunc(8, 5);
    //传递不同类型的参数，调用不同的函数
    double myNum2 = plusFunc(4.3, 6.26);
    
    cout << "Int: " << myNum1 << "\n";
    cout << "Double: " << myNum2;
    
    return 0;
}