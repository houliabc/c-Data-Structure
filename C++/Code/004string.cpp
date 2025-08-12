#include <iostream>
#include <string>
using namespace std;

int main(){
    string firstName = "Liu", lastName = "wen", s = firstName;
    string fullName = firstName + lastName;  //c++字符串可以相加
    cout << fullName << endl << endl;

    fullName = firstName.append(lastName);  //还可以用字符串的append方法
    cout << fullName << endl;
    cout << "The length of the fullName is " << fullName.length() << endl;
    cout << "The size of the fullName is " << fullName.size() << endl;  //相同的

    cout << fullName[0] << endl;

    // String to char
    printf("%s", s.c_str());
    return 0;
}