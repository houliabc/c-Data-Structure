# C++基础

## Linux中编译

### c++

使用 `g++ -v` 来检查是否安装过 `g++`。

使用如下命令可以安装：

**sudo apt install g++**

- 编译代码

`g++ test.cpp -o test -lm `

还可以编译多个文件：`g++ 文件1 文件2 -o test -lm `

指定c++标准版本：`g++ -std=c++11 文件1 -o 文件名`

`g++` 是 C++ 语言的编译器（C 语言的编译器为 `gcc`），**`-o` 用于指定可执行文件的文件名**，编译选项 `-lm` 用于链接数学库 `libm`，从而使得使用 `math.h` 的代码可以正常编译运行。

注：C++ 程序不需要 `-lm` 即可正常编译运行。历年 NOI/NOIP 试题的 C++ 编译选项中都带着 `-lm`，故这里也一并加上。

### C语言

**gcc test.cpp -o test -lm**

| gcc选项           | 作用描述                                             |
| ----------------- | ---------------------------------------------------- |
| `-o <文件名>`     | 指定输出文件名（可执行文件、库文件等）               |
| `-c`              | 只编译不链接，生成目标文件（.o）                     |
| `-g`              | 包含调试信息（用于 gdb 调试）                        |
| `-Wall`           | 开启所有警告信息                                     |
| `-Wextra`         | 开启额外警告（比 -Wall 更严格）                      |
| `-O0/-O1/-O2/-O3` | 优化等级（-O0 无优化，-O3 最高优化）                 |
| `-I <路径>`       | 指定头文件搜索路径（如 `-I include/`）               |
| `-L <路径>`       | 指定库文件搜索路径（如 `-L lib/`）                   |
| `-l<库名>`        | 链接动态库（如 `-lstdc++` 链接 C++ 标准库）          |
| `-static`         | 静态链接所有库（生成文件较大，但可在无依赖环境运行） |
| `-std=<标准>`     | 指定语言标准（如 `-std=c11`、`-std=c++20`）          |

## 基本语法

### C++「代码框架」

```cpp
#include <cstdio>
#include <iostream>

int main() {
  // do something...
  return 0;
}
```

> **什么是 include？**
>
> `#include` 其实是一个预处理命令，意思为将一个文件「放」在这条语句处，被「放」的文件被称为头文件。也就是说，在编译时，编译器会「复制」头文件 `iostream` 中的内容，「粘贴」到 `#include <iostream>` 这条语句处。这样，你就可以使用 `iostream` 中提供的 `std::cin`、`std::cout`、`std::endl` 等对象了。
>
> 如果你学过 C 语言，你会发现目前我们接触的 C++ 中的头文件一般都不带 `.h` 后缀，而那些 C 语言中的头文件 `xx.h` 都变成了 `cxx`，如 `stdio.h` 变成了 `cstdio`。因为 C++ 为了和 C 保持兼容，都直接使用了 C 语言中的头文件，为了区分 C++ 的头文件和 C 的头文件，使用了 `c` 前缀。
>
> 一般来说，应当根据你需要编写的 C++ 程序的需要来确定你要 `#include` 哪些头文件。但如果你 `#include` 了多余的头文件，只会增加编译时间，几乎不会对运行时间造成影响。目前我们只接触到了 `iostream` 和 `cstdio` 两个头文件，如果你只需要 `scanf` 和 `printf`，就可以不用 `#include <iostream>`。
>
> 可以 `#include` 自己写的头文件吗？答案是，可以。
>
> 你可以自己写一个头文件，如：`myheader.h`。然后，将其放到和你的代码相同的目录里，再 `#include "myheader.h"` 即可。需要注意的是，自定义的头文件需要使用引号而非尖括号。当然，你也可以使用编译命令 `-I <header_file_path>` 来告诉编译器在哪找头文件，就不需要将头文件放到和代码相同的目录里了。

### 输入与输出

1. `cin`与`cout`
2. `scanf` 与 `printf` 

其实是 C 语言提供的函数。大多数情况下，它们的速度比 `cin` 和 `cout` 更快，并且能够方便地控制输入输出格式。

## 变量

### 布尔类型

用bool

只有true和false

### 字符类型

窄字符型位数一般为 $8$

- `signed char`：有符号字符表示的类型，表示范围在 -128 - 127 之间。
- `unsigned char`：无符号字符表示的类型，表示范围在 0 - 255 之间。
- `char` 拥有与 `signed char` 或 `unsigned char` 之一相同的表示和对齐，但始终是独立的类型。

> `char` 的符号性取决于编译器和目标平台：ARM 和 PowerPC 的默认设置通常没有符号，而 x86 与 x64 的默认设置通常有符号。
>
> 与其他整型不同，`char`、`signed char`、`unsigned char` 是 **三种不同的类型**。
>
> 一般来说 `signed char`,`unsigned char` 不应用来存储字符，绝大多数情况下，这两种类型均被视作整数类型。

### 浮点类型

用于存储「实数」（注意并不是严格意义上的实数，而是**实数在一定规则下的近似**），包括以下三种：

- `float`：单精度浮点类型。如果支持就会匹配 IEEE-754 binary32 格式。
- `double`：双精度浮点类型。如果支持就会匹配 IEEE-754 binary64 格式。
- `long double`：扩展精度浮点类型。如果支持就会匹配 IEEE-754 binary128 格式，否则如果支持就会匹配 IEEE-754 binary64 扩展格式，否则匹配某种精度优于 binary64 而值域至少和 binary64 一样好的非 IEEE-754 扩展浮点格式，否则匹配 IEEE-754 binary64 格式。

| 浮点格式                   | 位宽      | 最大正数                   | 精度位数         |
| :------------------------- | :-------- | :------------------------- | :--------------- |
| IEEE-754 binary32 格式     | $32$      | $3.4\times 10^{38}$        | $6\sim 9$        |
| IEEE-754 binary64 格式     | $64$      | $1.8\times 10^{308}$       | $15\sim 17$      |
| IEEE-754 binary64 扩展格式 | $\geq 80$ | $\geq 1.2\times 10^{4932}$ | $\geq 18\sim 21$ |
| IEEE-754 binary128 格式    | $128$     | $1.2\times 10^{4932}$      | $33\sim 36$      |

> IEEE-754 **浮点格式的最小负数是最大正数的相反数**。

因为 `float` 类型表示范围较小，且精度不高，**实际应用中常使用 `double` 类型表示浮点数**。

另外，浮点类型可以支持一些特殊值：

- **无穷（正或负）：`INFINITY`.**——需要导入`<cmath>`
- **负零：`-0.0`，例如 `1.0 / 0.0 == INFINITY`,`1.0 / -0.0 == -INFINITY`.**
- **非数（NaN）：`std::nan`,`NAN`，一般可以由 `0.0 / 0.0` 之类的运算产生。它与任何值（包括自身）比较都不相等，C++11 后可以 使用 `std::isnan` 判断一个浮点数是不是 NaN**.

### 空指针类型

**std::nullptr_t**

注意这是一个类型，意味着可以定义属于该类型的变量

```cpp
#include <iostream>
#include <cmath>
using namespace std;

int main() {
        nullptr_t p = nullptr;  // C++11引入的nullptr
        cout << p << endl;  // 输出nullptr的地址，通常为0
}
```

# C++高级

## 迭代器

### 定义

很多数据结构并不是线性的（例如红黑树），对于非线性数据结构，下标是无意义的。无法使用下标来遍历整个数据结构。

迭代器的作用就是定义某个数据结构的遍历方式，通过迭代器的增减，代表遍历到的位置，通过迭代器便能成功遍历非线性结构了。（**行为类似指针**）

```cpp
for (vector<int>::iterator it = a.begin(); it != a.end(); ++it)
    cout << *it << endl;
```

- `a.begin()` 是一个迭代器，指向的是第一个元素
- `a.end()` 是一个迭代器，指向的是最后一个元素**再后面一位**
- 上述迭代器具有自增运算符，自增则迭代器向下一个元素移动
- 迭代器与指针相似，如果对它使用解引用运算符，即 `*it`，就能取到对应值了

### 用法

对于 vector 容器，它的迭代器功能比较完整，以它举例：

- `.begin()`：头迭代器
- `.end()`：尾迭代器
- `.rbegin()`：反向头迭代器
- `.rend()`：反向尾迭代器
- 迭代器 `+` 整型：将迭代器向后移动
- 迭代器 `-` 整型：将迭代器向前移动
- 迭代器 `++`：将迭代器向后移动 1 位
- 迭代器 `--`：将迭代器向前移动 1 位
- 迭代器 `-` 迭代器：两个迭代器的距离
- `prev(it)`：返回 it 的前一个迭代器
- `next(it)`：返回 it 的后一个迭代器

对于其他容器，由于其结构特性，上面的功能不一定都有（例如 set 的迭代器是不能相减求距离的）

> **`.end()` 和 `.rend()` 指向的位置是无意义的值**
>
> 注意插入和删除的情况元素变动会对迭代效果产生影响

# 数据结构容器

## 动态数组 vector

动态数组与c语言自带的数组最大的区别是其内存分配是动态的，会随着你插入删除动态的变化，而不是固定死的，很多浪费的空间

需要导入vector模块

### 一维 vector

定义方式：

**vector<类型（甚至可以是另一个vector）> name;**

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> nums(3);  // 数组中默认值是0
    cout << nums[2] << endl;

    // vector的n种插入方式
    nums.push_back(20);
    cout << nums[3] << endl;
    // 在尾部直接构造一个元素
    nums.emplace_back(30);  // 直接构造元素，无需临时对象
    cout << "emplace_back后的最后一个元素: " << nums.back() << endl;
    // 在指定索引位置处插入一个元素（使用insert，此方法会移动后面的元素，效率较低）
    nums.insert(nums.begin() + 0, 99);  // nums.begin() 返回的是一个迭代器
    // emplace同样可以实现insert的功能
    nums.emplace(nums.begin() + 2, 199);  
    // 修改第2个元素为30，会检查越界，越界会抛出异常
    nums.at(1) = 30;  

    // 获得最后一个元素
    cout << nums.back() << endl;

    // 删除最后一个元素
    nums.pop_back();

    // 删除索引处的元素
    nums.erase(nums.begin() + 1);

    // 交换数组元素
    swap(nums[0], nums[1]);

    // 遍历数组
    cout << "最终数组元素: ";
    for (int i = 0; i < nums.size(); i++)
        cout << nums[i] << ' ';
    cout << endl;

    // 重新分配5个元素，所有元素初始化为100
    nums.assign(5, 100);  
    cout << "assign后的数组元素: ";
    for (int i = 0; i < nums.size(); i++)
        cout << nums[i] << ' ';
    cout << endl;

    return 0;
}
```

### 二维 vector

区别在于定义数组类型是另一个vector，像套娃一般

```cpp
#include <iostream>
#include <vector>
using namespace std;

// 将函数定义移到main()外部（全局作用域）
void printVector(const vector<vector<int>>& vec) {
    for (const auto& row : vec) {
        for (int val : row) {
            cout << val << "\t";
        }
        cout << endl;
    }
}

int main() {
    // ====================== 1. 初始化二维vector ======================
    vector<vector<int>> matrix1(3, vector<int>(4, 0));
    cout << "matrix1[1][2] = " << matrix1[1][2] << endl;

    vector<vector<int>> matrix2;
    vector<int> row1 = {1, 2, 3};
    vector<int> row2 = {4, 5, 6, 7};
    matrix2.push_back(row1);
    matrix2.push_back(row2);
    cout << "matrix2行数: " << matrix2.size() << endl;
    cout << "第二行列数: " << matrix2[1].size() << endl;

    // ====================== 2. 元素操作 ======================
    matrix1[0][1] = 100;
    matrix2[1][3] = 99;
    matrix1.push_back({200, 300});
    matrix2[0].push_back(4);

    // ====================== 3. 遍历二维vector ======================
    cout << "\n=== 下标遍历 matrix1 ===" << endl;
    for (int i = 0; i < matrix1.size(); i++) {
        for (int j = 0; j < matrix1[i].size(); j++) {
            cout << matrix1[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "\n=== 范围for遍历 matrix2 ===" << endl;
    for (const auto& row : matrix2) {
        for (int val : row) {
            cout << val << "\t";
        }
        cout << endl;
    }

    // ====================== 4. 二维vector常用函数 ======================
    int rows = matrix1.size();
    int cols = (rows > 0) ? matrix1[0].size() : 0;
    cout << "\nmatrix1行数: " << rows << ", 列数: " << cols << endl;

    matrix1.clear();
    cout << "matrix1清空后行数: " << matrix1.size() << endl;

    if (matrix1.empty()) {
        cout << "matrix1已为空" << endl;
    }

    // ====================== 5. 二维vector传参给函数 ======================
    cout << "\n=== 函数打印 matrix2 ===" << endl;
    printVector(matrix2);  // 正确调用外部定义的函数

    return 0;
}
```

## 哈希表 unordered_map

类似于python中的字典

**特别注意：访问不存在的键会自动插入键值对**

使用需要导入模块`<unordered_map>`

```cpp
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
```

## 哈希集合 unordered_set

于存储不重复的元素，常见使用**场景是对元素进行去重**。

导入模块`<unordered_set>`

```cpp
#include <iostream>
#include <climits>
#include <unordered_set>

using namespace std;

int main() {
    // unordered_set 是 C++ 标准库中的一种哈希集合实现，用于存储不重复的元素，常见使用场景是对元素进行去重。
    unordered_set<int> mySet{1, 2, 4, 5};

    cout << mySet.empty() << endl; 

    cout << mySet.size() << endl;

    // 查找元素是否存在的三种方法
    if (mySet.find(3) != mySet.end()) {
        cout << "Found 3 in the set." << endl;
    } 
    else if (!mySet.contains(3)){
        cout << "3 not found in the set." << endl;
    }
    else if (mySet.count(3) > 0) {
        cout << "Found 3 in the set." << endl;
    } else {
        cout << "3 not found in the set." << endl;
    }

    // 插入元素的几种方法
    mySet.insert(3); 
    // 以下两种方法都是后插入的元素在前，也就是头插法
    mySet.emplace(6); // emplace 直接构造元素
    mySet.insert({7, 8}); // 插入多个元素
    
    // 遍历集合
    for (const auto& element: mySet) {
        cout << element << " ";
    }
    cout << endl;

    mySet.erase(3);
     if (mySet.count(3) > 0) {
        cout << "Found 3 in the set." << endl;
    } else {
        cout << "3 not found in the set." << endl;
    }

    mySet.clear();
    cout << mySet.empty() << endl;

    return 0;
}
```

