#include <iostream>
#include <climits>
#include <vector>

using namespace std;
// 2.63
unsigned srl(unsigned x, int k) {
    // Perform shift arithmeticall
    unsigned xsra = (int) x >> k;  // 当前是算术右移，之后的操作不允许用右移或除法
    int w = sizeof(int) << 3;  // 计算 int 位数
    // 想办法完成逻辑右移：算数右移的高k位为1/0，那只需要将高k位转换成0，强制变成0即可实现逻辑右移
    int mask = -1 << (w - k);  // 形如1..1000..0
    return (mask | xsra) & ~mask;
}

unsigned sra(int x, int k) {
    // Perform shift logicall
    int xsral = (unsigned) x >> k;  // 当前是逻辑右移：高k位全是0。之后的操作不允许用右移或除法
    int w = sizeof(int) << 3;  // 计算 int 位数
    // 想办法完成算术右移：高k位取决于x的符号位，也就是把高k位变成0或1
    int sign = x & (1 << 31);
    int mask = -1 << (w - k);
    // 用到了lab实验里的实现： x?y:z 
    int condition = ~(!!sign) + 1;  // 符号位为1则为-1（需要将高k位变为1），否则是0（结果和逻辑右移相同）
    return (~condition & x) | (condition & (xsral | mask));
}

// 2.64
int any_odd_one(unsigned x) {
    // Return 1 when any odd bit of x equals 1; 0 otherwise
    // 当x有任意奇数位等于1时返回1，否则返回0
    // 计算机中，位的编号通常从0 开始（从右往左，最低有效位为第 0 位）
    return !!(x & 0xaaaaaaaa);
}

// 2.65
//Return 1 when x contains an odd number of 1s; 0 otherwise
// 当x包含奇数个1时返回1；否则返回0
int odd_ones(unsigned x) {
    x ^= x >> 16;  // 高16位与低16位异或
    x ^= x >> 8;   // 前8位与后8位异或
    x ^= x >> 4;   // 前4位与后4位异或
    x ^= x >> 2;   // 前2位与后2位异或
    x ^= x >> 1;   // 前1位与后1位异或
    return x & 1;
    // // 异或运算的本质：统计该位上 1 的个数的奇偶性
    // int parity = 0;
    // for (int i = 0; i < 32; i++) {
    //     parity ^= (x >> i) & 1;  // 逐位提取并异或
    // }
    // return parity;
}

// 2.66
/*
* Generate mask indicating leftmost 1 in x. Assume w=32.
* For example, OxFFOO -> Ox8000, and Ox6600 --> Ox4000.
* If x = 0, then return 0.
*/
int leftmost_one(unsigned x) {
    // 首先将x变为最高位的1右边全为1的形式
    // 通过逐项右移的方式可以实现，不管最高位是几，反正可以保持最高位右边都是1，因为用的是或运算（加法）
    unsigned y = x;
    y |= x >> 1;
    y |= y >> 2;
    y |= y >> 4;
    y |= y >> 8;
    y |= y >> 16;  // 到此为止，移动了31位了
    // 接着用异或操作来计算出最左边的1
    return y ^ (y >> 1); // 错开1位，这样异或能取到最高位
}

// 2.67
// 编写 一个过程 int_size_is_32 (), 当在 一个 int 是 32 位的机器上运行时，该 程序产生 1, 而其他情况则产生 0 。不允许使用 sizeof 运算符
// 至少32位
int int_size_is_32() {
  int set_msb = 1 << 31;
  int beyond_msb = set_msb << 1;

  return set_msb && !beyond_msb;
}
// 至少16位
int int_size_is_32_for_16bit() {
  int set_msb = 1 << 15 << 15 << 1;
  int beyond_msb = set_msb << 1;

  return set_msb && !beyond_msb;
}

// 2. 68 写出具有 如下原型的函数的代码：
/*
* Mask with least signficant n bits set to 1
* Examples: n = 6 --> Ox3F, n = 17 --> Ox1FFFF
* Assume 1 <= n <= w
*/
int lower_one_mask(int n) {
    // 得到高n位为1（第一位排除）
    int mask = ((1 << 31) >> n) ^ (1 << 31);
    // 接着向右位移就可以
    return mask >> (31 - n);
}

// 2. 69 写出具有如下原型的函数的代码：
/*
* Do rotating left shift. Assume O <= n < w
* Examples when x = Ox12345678 and w = 32:
* n=4 -> Ox23456781, n=20 -> Ox67812345
*/
unsigned rotate_left(unsigned x, int n) {
    // 思路大概是分两部分处理，1是提取左边的，2是提取右边的，之后把右边放左边，左边放右边
    unsigned left = x << n;  // 右端会为0
    // 注意看这题给的是unsigned的x，这就表明我们的右移都是逻辑右移，左边是用0填充的，这就不用担心了
    unsigned right = x >> (32 - n);
    return right | left;
}

// 2. 70 写出具有如下原型的函数的代码：
/*
* Return 1 when x can be represented as an n-bit, 2's-complement
* number; 0 otherwise
* Assume 1 <= n <= w
*/
int fits_bits(int x, int n) {
    // 当x可以被表示为一个n位（n可能比W小）的二进制补码时，返回1 ，否则0
    int w = sizeof(x) << 3;
    int offSet = w - n;
    return !((x << offSet >> offSet) ^ x);
}











int main() {
    unsigned x = 0xFFFFFFFF;
    cout << hex << srl(x, 1) << endl; // 期望输出: 0x7FFFFFFF
    cout << hex << sra(x, 1) << endl; // 期望输出: 0xFFFFFFFF
    
    cout << any_odd_one(0xBBBBBBB9) << endl; // 期望输出: 1

    cout << odd_ones(9) << endl; // 期望输出: 1

    cout << leftmost_one(0x6600) << endl;

    cout << int_size_is_32() << endl;

    cout << int_size_is_32_for_16bit() << endl;

    cout << lower_one_mask(17) << endl;

    cout << rotate_left(0x12345678, 20) << endl;

    cout << fits_bits(0b00000110, 3) << endl;  // 0，因为3位的x的最高位是1，是负值

    cout << "-----------" << endl;

    cout << (!0) << endl;
    cout << (0xffffffff >> 1) << endl;
    cout << (~0u >> 1) << endl;
    cout << !(0xAAAAAAAA ^ (0xFFFFFFFD & 0xAAAAAAAA)) << endl;
    cout << (~(-1)) << endl; 
    return 0;
}