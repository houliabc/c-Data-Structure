---

---





# CSAPP lab环境配置

## 安装

打开Linux终端（我用的是Ubuntu），安装：

```ubuntu
sudo apt-get install build-essential
sudo apt-get install gcc-multilib
sudo apt-get install gdb
```

## labs下载地址

https://github.com/houliabc/c-Data-Structure/releases

可以通过Ubuntu中的git命令下载，也可以Windows下载使用类似“FileZilla Client”的软件上传到命令行中，具体的使用可能需要查一下



# CSAPP lab第二章datalab

您的目标是修改bits.c的文件，使其通过btest中的所有测试，而不违反任何编码准则。

## 评分脚本

为了达到bits.c文件的得分评比和报错情况或者违反编码准则的情况，我编写了一个方便的脚本：

先进入到datalab-handout目录，输入命令

```
vim run.sh
```

之后**按下i键，粘贴内容**：

```shell
#/bin/bash
make clean
make
./btest
echo "--------------------------------------------------------------------------------"
./dlc -e bits.c
```

**按下esc键，之后按两次大写字母Z保存退出**，接着，你就可以通过一行命令来实现检测了

```shell
bash ./run.sh
```

- 建议：每写完一道题，就保存退出执行一下上述命令，这样可以检查你这道题做对没有，不要全部做完再来（踩坑的我）！

## bitXor

这是第一道题，但对于新人还是不那么友好的：**用位表示异或运算：“^”**



首先要明白什么是异或，口诀是：**不同为1，相同为0。**

例如：0b1011 ^ 0b0001 = 0b1010

这道题我是自己通过在草稿纸反复推链推出的，可能花了有半个小时到一个小时，我压根就不会本题的“徳摩根定理”，纯粹用题目要求的“~”和“&”，来想办法得出结果，所以我也讲不了什么，暂时不会可以跳过下一道题。

```c
/* 
* bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  return ~(~(x & ~y) & ~(y & ~x));
}
```

## tmin

**求最小的补码**



这是本章lab最简单的一道题，纯粹是从补码定义和补码表示出发

```c
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  return 1 << 31;
}
```

## isTmax

**如果x是补码的最大值则返回1，否则0**



我们**先假定x是最大值**的情况，最大值是形如：0b01111..1 的形式，当x + 1 时，就为0b100..0

我们**一般用异或操作来判断两个值是否相等**，那么**如果x是最大值，那 ~(x + 1)的值就应该是他本身**，再通过异或运算和逻辑非，即可得到是否是最大值的情况。

但是我们发现x为 0b11...1 也就是 -1 时， ~(x + 1)也等于它本身，那么我们考虑想办法去掉该值。

也同样是运用异或的办法，最后通过**两次非操作来“格式化”结果，即转换成只有1或0**的情况

```c
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
  // 左边是判断是否是TMAX，右边是排除11111..的情况
  // !!是一个格式化的操作，对于非0值会返回1，而0值就返回0
  return (!(~(x + 1) ^ x) & !!((x + 1) ^ 0x0));
}
```

## allOddBits

**如果所有的奇数位上都为1，则返回1，否则0**



需要注意的是，从右到左的二进制的第一个数字并不是第一位，而是第零位；第二个数字开始才是第一位

那么也就是当出现1至少在这些位数上出现时才为真： 0b1010|1010|1010|1010 也就是 0xAAAAAAAA

1. 第一步先取出上面为1的位数对应的值
2. 第二步通过与“x == y” 等价的位操作“!(x  ^  y)” 来判断是否满足题目的要求

```c
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  int one = 0xAA, two = one | (one << 8), three = two | (two << 8), mask = three | (three << 8);
  return !(mask ^ (x & mask));
//  return !(0xAAAAAAAA ^ (x & 0xAAAAAAAA));
}
```

## negate

给你 x 求 -x



也是其中最简单的一道题，完全是定义出发，这道题我记得书上有一模一样的

```c
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return ~x + 1;
}
```

## isAsciiDigit

判断x是否是数字0-9



1. 首先，满足数字的二进制只会用到低6位，剩下的高26位都为0
2. 根据 0x30 <= x <= 0x39，那么十六进制的第一位必为3，第二位范围在 0 - 9，所以难点就在于如何判断是否在范围内
3. 可以发现第二位最大值是9，那么减去 ‘a’（十六进制）则必小于0，否则不成立

```c
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  // 如何表示范围呢？不用大于小于的话
  // Assume x is 0xMN
  // check1: check whether or not the M is 3
  // check1: check whether or not the N is between 0 and 9
  // 还需要使高26位清除掉
  int zero = x >> 6;  // 如果有高26位则不成立
  int first = 0x30 ^ (x & 0xf0);  // 相同则为0
  // I can use 0xF minus
  int second = (x & 0xf);  // 截取低4位
  int minus = (second + ~0x9) >> 31;   // 该第四位满足条件：second - 'a' < 0成立，否则就不符合
  return (!zero & !first & !!minus);
}
```

## conditional

用位操作实现条件运算符 “x ? y : z ”



像这种要么返回y，要么返回z的情况，一定是用到了 | 连接的

```c
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
//   思路：
// 用倒推的思路，返回值二选一，return结果一定是用 | 连接
// 而一个返回y，一个返回z，返回原值可以用补码全1（即-1）和&来实现，返回0可用0和&来实现
// 定义中间量condition=-1或0，condition需要与x相关联，则可以用!!x和取相反数的操作来实现
// 当 x!=0时，!!x=1, condition=~(!!x)+1=-1
// 当 x= 0时，!!x=0, condition=~(!!x)+1= 0
  int condition = ~(!!x) + 1;
  // condition = (!!x << 31) >> 31  //也可以这样，如果是1左移后再右移会触发算数右移，1会填充左边，最后的结果是-1；0的话最终结果是0，和上一个式子等价
  return (condition & y) | (~condition & z);
}
```

这题的关键是找一个condition，使得 (condition & y)和(~condition & z) 中一个为0，一个不为0

## isLessOrEqual

用位运算表示 x <= y

```c
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  // 思路是用减法，y - x，之后再看符号位，符号位0 表示正值，也就是返回1；符号位1表示负值，返回0
  int condition = y + (~x + 1);
  int top = condition >> 31; // 记录最高位，0表示y大与等于，返回1；1表示x大，返回0
  return !top;	
}
```

## logicalNeg

用位运算表示非运算 !

```c
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
//   思路：
// 运用0的性质，0的相反数还是0，按位或得到的值还是0（最高位也为0）。所以当x为0时，就返回0
// 其他值（非0值）与相反数按位或得到的最高位为1（值与相反数总有一个是负数），但如果右移后就是-1（触发算术右移）
  int first = x >> 31;
  int two = (~x + 1) >> 31;  // 如果符号位为0，那这里会触发算数右移，结果是-1
  return 1 + (first | two);  // 加1是为了使原本的值域【-1，0】转变为【0，1】，才能符合题目
}
```

## howManyBits

使用补码时最少需要多少位表示

```c
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
// 首先要理解题目对位数的定义，负数可以就按正常补码的理解，而正数则要在正常的基础上加上一个符号位0，例如
// howManyBits(12) = 5—>0 1 1 0 0,为五位，而非四位。

// 为了便于处理，我们将负数统一取反，之所以可以这么做是因为，为了确定负数用补码表示最少需要几位，则需要找到负数中从高位开始第一个为零的位，取反后则需要找到第一个为1 的位，实现的效果其实相一致 （实在不明白可以在纸上画一画）。

// 就像上面说的，我们需要找到第一个 1 的位置，得出从该位置算起有多少位，再加上一个符号位，就可以得出一个数用补码表示最少需要几位。
// 但难点在于我怎么去确定二进制数列中第一个1的位置。大佬写的是一种放缩的思维，首先我要假设一下一系列操作均成立：
// 假设1在高16位中，然后将x右移16位，则该补码至少需要16位。
// 假设1在高8位中，然后将x右移8位，则该补码至少需要16+8位。
// 假设1在高4位中，然后将x右移4位，则该补码至少需要16+8+4位。
// 假设1在高2位中，然后将x右移2位，则该补码至少需要16+8+4+2位。
// 假设1在高1位中，然后将x右移1位，则该补码至少需要16+8+4+2+1位。
// 最后不要忘记符号位，再加上1，则该补码至少需要16+8+4+2+1+1位。

  int sign = x >> 31;  // 取符号位
  // 如果x为正则不变，否则按位取反（这样好找最高位为1的，原来是最高位为0的，这样也将符号位去掉了）
  x = (sign & ~x) | (~sign & x);

  // 放缩来不断地缩小范围
  // 判断高十六位是否有1
  int b16 = !!(x >> 16) << 4;
  // 若有这至少需要16位，则将原数右移16位
  x >>= b16;
  // 接着判断16位后的高8位是否有1，有则继续位移8位
  int b8 = !!(x >> 8) << 3;
  x >>= b8;
  int b4 = !!(x >> 4) << 2;
  x >>= b4;
  int b2 = !!(x >> 2) << 1;
  x >>= b2;
  int b1 = !!(x >> 1);
  x >>= b1;
  int b0 = x;

  return b16 + b8 + b4 + b2 + b1 + b0 + 1;  // 加一位是符号位
}
```

挺难的一道题，我也是参考了大佬的写法才看懂了，之后的题就是浮点数的了，会偏难些，不过可以使用if、while、|| 这些表达式了，解除了很多只能使用位运算的限制

## floatScale2

**返回与二进制相同的浮点数表示**



需要从IEEE浮点数的定义入手：

![image-20250531163705391](https://houlir2.dpdns.org/2025/08/4d7189a3a7e59eb523367c1e16bc1df0.png)

![image-20250531164208238](https://houlir2.dpdns.org/2025/08/dfa960ff61f46b4e19883647c962d00a.png)

即根据exp值分为几种情况，要分别判断

```c
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
  int exp = (uf & 0x7f800000) >> 23;  // 尾数有23位
  int sign = uf & (1 << 31);
  int frac = uf & 0x7fffff;
    
  // 先处理一些特殊的情况
  // 0
  if (frac == 0 && exp == 0)
    return uf;

  // 非规格化
  if (exp == 0)
    // << 1 表示乘2，正是题目要求的2*f
    return frac << 1 | sign;

  // 无穷大直接返回
  if (exp == 0xff) return uf;

  // 规格化的情况
  exp++;  // 这里是通过指数加1的方式来实现*2的效果
  // 如果指数+1之后，指数为255则返回原符号无穷大，否则返回指数+1之后的原符号数。
  return sign | exp << 23 | frac;
}
```

## floatFloat2Int

**返回与二进制相同的浮点数取整表示**



思路都差不多，主要是针对转换成整形的一些溢出的修正，下面是浮点数的另一些知识：

1. **规格化（一般化）的情况：**

   当**exp 或 e 的位不全为0或1时**，就属于该情况。此时阶码 **$E = e - Bias$**。其中 **e 就是上面蓝色部分的二进制位表示的无符号正数，而Bias是一个固定的值，其值根据阶码的位数来决定，如单精度时，k = 8，此时 $bias = 2^{k-1} - 1 = 2 ^ 7 - 1 = 127$（双精度是1023）**，由此可得：

   - **E = e - 127**   （**单**精度的情况）
   - **E = e - 1023**  （**双**精度的情况）

2. **非规格化（不一般）的情况：**

   当**exp 或 e 的位全为0时**，此时阶码 **$E = 1 - Bias = 1 - 127 = -126$（单精度情况下），而 M = f**

| 精度                 | 符号位(s) | 阶码位(exp 或 k位 或 无符号数e) | 尾数位(frac 或 M) |
| -------------------- | --------- | ------------------------------- | ----------------- |
| 单精度（float）32位  | 1         | **8（bias = 127）**             | **23**            |
| 双精度（double）64位 | 1         | **11（bias = 1023）**           | **52**            |

```c
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
  unsigned frac = uf & 0x7fffff;
  unsigned exp = (uf >> 23) & 0xff;
  unsigned sign = uf & (1 << 31);

  // 0，包括非规格化的情况
  if (exp == 0)
	return 0;
  // 无穷大
  else if (exp == 0xff)
  	return 1 << 31;
    
  // 规格化的情况
  // 阶码E的计算
  int E = exp + ~(126); // ~(126)就是-127，即那个bias
  frac = frac | 1 << 23;

  // 判断超出整数范围的情况
  if (E > 31)
	return 1 << 31;  // 这就是题目要求的0x80000000u
  // 表示无穷小			   
  else if (E < 0)
	return 0;

  // M * 2^E
  if (E >= 23) // 超过frac所能表示的位数
	frac <<= (E - 23);
  else
	frac >>= (23 - E);

  // 判断符号位
  if (!!sign) // 负值
	return  ~frac + 1;
  return frac;
}
```

## floatPower2

**返回`2.0`的`x`次方的位级等价表示**

```c
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) {
    // 这里的x应该是E，所以x = exp - bias
    // x的范围：(-126-23) - 127+
    // denormalize：阶码全为0，此时x<=-126，frac可以是最小的-2^23，也可以是最大的2^22 + 2^21 + 2^20 .. + 2^0
    // 最小的情况
    if (x <-149)
	    return 0;
    // 因为有2^0所以取最大的阶数也是2^-126
    else if (x < -126){
    	    int exp = x + 126;
	    return 1 << (23 + exp);
    }

    // normalize	   
    else if (x <= 127) {
	    int exp = x + 127;
	    return exp << 23;
    }
    else  //无穷大
	    return 0xff << 23;
    return 2;  // 此时f为1
}
```

# CSAPP homework第二章

正确的刷题顺序应该是先做完homework，接着才是labs，不然直接做labs难度会更难（我踩过的坑），很多labs题可以在homework中找到类似的思路

有些没啥用的题我就没有做了，我挑了自己认为值得做的，如果需要完整的可以参考以下别人的链接：

https://www.cnblogs.com/machao/p/8397961.html

## 2.58 is_little_endian

编写过程is_little_endian，在小端法机器运行返回1，大端法返回0，无论机器字长



通过对1（0x0001）强制转成char类型的方式，看剩下的那一个字节是多少，因为十进制 1 的左侧（十六进制）是0，右侧是1，所以可以由此判断是大端法还是小段法

```c
typedef unsigned char *byte_pointer;
int is_little_endian() {
	short s = 1;
	byte_pointer p = (byte_pointer) &s;
	return *p;
}

int main() {
    if (is_little_endian()) {
        cout << "小端字节序" << endl;
    } else {
        cout << "大端字节序" << endl;
    }
    return 0;
}
```

## 2.59

![img](https://houlir2.dpdns.org/2025/08/256c7f2c9e97188702292839c175ec82.png)

左边取x的低1字节，右边取y的高3字节（通过取反低1字节）

```cpp
int main() {
    int x = 0x89ABCDEF; 
    int y = 0x76543210; 
    cout << hex << showbase << uppercase << ((x & 0xFF)|(y & ~0xFF));  // 输出结果为0x765432EF
    cout << '\n';
    return 0;
}
```

## 2.60 replace_byte

![img](https://houlir2.dpdns.org/2025/08/f7090b52120245e3959e3a31a701905b.png)

```cpp
#include <iostream>
using namespace std;

// 从x中抽取最高有效字节
int get_msb(int x) {
    // shitf_val是一个整数，表示要将x右移多少位以获取最高有效字节
    int shift_val = (sizeof(int) - 1) << 3;
    int shift_x = x >> shift_val;  // 将x右移到最高有效字节的位置
    return shift_x & 0xFF;  // 取出最高有效字节
}

unsigned replace_byte(unsigned x, int i, unsigned char b) {
    int shift = i << 3;          // 计算字节i的移位量（8位/字节，左移3位即乘8）
    unsigned mask = ~(0xFF << shift);  // 构造掩码：除第i字节外全为1（清除第i字节的位）
    unsigned byte_b = (unsigned)b << shift;  // 将b移到第i字节的位置
    return (x & mask) | byte_b;  // 清除x的第i字节，再与b的字节进行或运算
}

int main() {
    int x = 0x12345678;
    int msb = get_msb(x);
    cout << "最高有效字节: " << hex << showbase << msb << endl;
    // cout << (0xFF<<1<<1<<1<<1);
    unsigned result = replace_byte(x, 2, 0xAB);
    cout << "替换后的结果: " << hex << showbase << uppercase << result << endl;  // 输出结果为0x89AB12EF    
    return 0;
}
```

## 2.61

![img](https://houlir2.dpdns.org/2025/08/bc6315f5404e467b7dc685b480a5f7ca.png)

用异或后取非来代替相等（==）

```c
int judge(int x) {
    return !~x || !x || !((x & 0xFF) ^ 0xFF) || !(x & 0xff000000);
}
```

## 2.62 int_shifts_are_arithmetic

```c
#include <iostream>
#include <climits>
#include <vector>

using namespace std;

int int_shifts_are_arithmetic() {
    int x = -1; // 0xFFFFFFFF
    return (x >> 1) == -1;
}

int main() {
    cout << int_shifts_are_arithmetic() << endl;  // 经过试验，该机器是算数右移的机器
    return 0;
}
```

## 2.63

![img](https://houlir2.dpdns.org/2025/08/96114b0f6ffe126d0dac3accf5bd3fe0.png)

简单来说第一个就是给你算术右移，要你变成逻辑右移；

第二个就是给你逻辑右移，返回算术右移

```c
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
```

## 2.64 any_odd_one

![img](https://houlir2.dpdns.org/2025/08/41e8fec7c3517d4e8a45926f13b0ea68.png)

```c
// 2.64
int any_odd_one(unsigned x) {
    // Return 1 when any odd bit of x equals 1; 0 otherwise
    // 当x有任意奇数位等于1时返回1，否则返回0
    // 计算机中，位的编号通常从0 开始（从右往左，最低有效位为第 0 位）
    return !!(x & 0xaaaaaaaa);
}
```

## 2.65

![img](https://houlir2.dpdns.org/2025/08/41e8fec7c3517d4e8a45926f13b0ea68.png)

当x包含奇数个1时返回1；否则返回0

```c
// 2.65
//Return 1 when x contains an odd number of 1s; 0 otherwise
int odd_ones(unsigned x) {
    // 本题运用到了异或运算的本质：统计该位上 1 的个数的奇偶性
    // 方法一
    x ^= x >> 16;  // 高16位与低16位异或
    x ^= x >> 8;   // 前8位与后8位异或
    x ^= x >> 4;   // 前4位与后4位异或
    x ^= x >> 2;   // 前2位与后2位异或
    x ^= x >> 1;   // 前1位与后1位异或
    return x & 1;
    
    // 方法二 
    // int parity = 0;
    // for (int i = 0; i < 32; i++) {
    //     parity ^= (x >> i) & 1;  // 逐位提取并异或
    // }
    // return parity;
}
```



## 2.66

![img](https://houlir2.dpdns.org/2025/08/15060c909940819b120bd8c9e2a7ad79.png)

```c
// 2.66
/*
* Generate mask indicating leftmost 1 in x. Assume w=32.
* For example, OxFFOO -> Ox8000, and Ox6600 --> Ox4000.
* If x = 0, then return 0.
*/
int leftmost_one(unsigned x) {
    // 首先将x变为最高位的1右边全为1的形式
    // 通过逐项右移的方式可以实现，不管最高位（最左边的第一个1）是几，反正可以保持最高位右边都是1，因为用的是或运算（加法）
    unsigned y = x;
    y |= x >> 1;
    y |= y >> 2;
    y |= y >> 4;
    y |= y >> 8;
    y |= y >> 16;  // 到此为止，移动了31位了
    // 接着用异或操作来计算出最左边的1
    return y ^ (y >> 1); // 错开1位，这样异或能取到最高位(除了最高位，其余位都是1，异或的结果就是0了)
}
```

## 2.67

![img](https://houlir2.dpdns.org/2025/08/c3361bab4f27f125827668a931326203.png)

```c
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
```

## 2.68

![img](https://houlir2.dpdns.org/2025/08/698e14186424a01165217b4709b9ad03.png)

```c
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
```

## 2.69

![img](https://houlir2.dpdns.org/2025/08/299f3800a073c9427197bf9b52ef1ca1.png)

```c
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
```

## 2.70

![img](https://houlir2.dpdns.org/2025/08/3de2940bd4da006c4486b40d5e6338d4.png)

```c
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
```

## 2.71

![img](https://houlir2.dpdns.org/2025/08/01497dff8dc364af73a73cb2fdb6bbda.png)

```cpp
#include <iostream>
#include <cassert>
using namespace std;

//2.71
typedef unsigned packet_t;
// 该函数的作用是取出一个字中的某个字节，然后把该字节扩展为有符号整数
// 难点在于如何利用算数右移填充前边的位
// 核心思想就是先把目前字节左移到最高位，然后再利用算数右移
int xbyte(packet_t word, int bytenum) {
    int size = sizeof(unsigned);
    int shift_left_val = (size - 1 - bytenum) << 3;
    int shift_right_val = (size - 1) << 3;
    return (int)word << shift_left_val >> shift_right_val;
}

int main(void) {
    // 测试
    cout << (xbyte(0x00112233, 2) == 0x11) << endl;
    cout << (xbyte(0x00112233, 0) == 0x33) << endl;
    cout << (xbyte(0x00112233, 1) == 0x22) << endl;
    cout << (xbyte(0x00112233, 3) == 0x00) << endl;

    cout << (xbyte(0xAABBCCDD, 0) == 0xFFFFFFDD) << endl;
    cout << (xbyte(0xAABBCCDD, 1) == 0xFFFFFFCC) << endl;
    cout << (xbyte(0xAABBCCDD, 2) == 0xFFFFFFBB) << endl;
    cout << (xbyte(0xAABBCCDD, 3) == 0xFFFFFFAA) << endl;
    cout << (xbyte(0xAABBCCDD, 3) == 0xFFFFFFAA);
    return 0;
}
```

## 2.73

![img](https://houlir2.dpdns.org/2025/08/ed5ca97a8e93fac9561e3a5424cb9c69.png)

```cpp
// 2. 73 写出具有如下原型的函数的代码：
//  Addition that saturates to TMin or TMax•I
// 编写饱和加法，同正常的补码加法溢出的方式不同，当正溢出时，饱和加法返回TMAX，负溢出时，返回TMIN，饱和运算常常用于在执行数字信号处理的程序中。
int saturating_add(int x, int y) {
    int sum = x + y;

    // 得到x 和 y 的符号位右移而成的掩码，0xff..f 表示的是负值，0x0 表示的是正值
    int x_sign_mask = x >> ((sizeof(int) << 3) - 1);
    int y_sign_mask = y >> ((sizeof(int) << 3) - 1);
    int sum_sign_mask = sum >> ((sizeof(int) << 3) - 1);

    // 接下来讨论正溢出和负溢出的情况：
    // 正溢出：当x > 0, y > 0时, sum < 0，即 x + y > sum
    // 当 x_sign_mask 和 y_sign_mask 都为 0x0(正值) ，sum_sign_mask 为 0xff.. （负值）的时候，此时必然是正溢出
    int pos_ovf = !x_sign_mask && !y_sign_mask && sum_sign_mask;   

    // 负溢出：当x < 0, y < 0时, sum > 0，即 x + y < sum
    // 当 x_sign_mask 和 y_sign_mask 都为 0xff..(负值) ，sum_sign_mask 为0（正值）的时候，此时必然是负溢出
    int neg_ovf = x_sign_mask && y_sign_mask && !sum_sign_mask;  
    
    // 构造选择掩码：溢出时为1，否则为0
    int ovf = pos_ovf | neg_ovf;

    // 正确选择结果：溢出时返回边界值，否则返回sum
    return ovf ? (pos_ovf ? INT_MAX : INT_MIN) : sum;
}

int main(void) {
    // 正常加法（无溢出）
    cout << "1 + 5 = " << saturating_add(1, 5) << endl;            // 输出: 6
    // 正溢出场景
    cout << "INT_MAX + 1 = " << saturating_add(INT_MAX, 1) << endl; // 输出: 2147483647 (INT_MAX)
    // 负溢出场景
    cout << "INT_MIN + (-1) = " 
         << saturating_add(INT_MIN, -1) << endl;                     // 输出: -2147483648 (INT_MIN)

    return 0;
}
```

## 2.74

![img](https://houlir2.dpdns.org/2025/08/22a263a0d403feb6dae2a4546b4bf1d0.png)

这个和上边的题目很相似，可以**把x-y看做x+（-y）**

```cpp
//  2. 74 写出具有如下原型的函数的代码：
// I* Determine whether arguments can be subtracted without overflow *I
// 如果计算 x-y 不溢出，这个函数就返回 1 。
int tsub_ok(int x, int y) {
    // 表示x - y
    int diff = x + (~y + 1);
    // 得到x 和 y 的符号位右移而成的掩码，0xff..f 表示的是负值，0x0 表示的是正值
    int w = (sizeof(int) << 3) - 1;
    int x_sign = x >> w;
    int y_sign = y >> w;
    int diff_sign = diff >> w;

    // 正溢出：x为正，y为负，且差值为负
    int pos_overflow = (!x_sign && y_sign && diff_sign);
    
    // 负溢出：x为负，y为正，且差值为正
    int neg_overflow = (x_sign && !y_sign && !diff_sign);
    
    // 溢出时返回0，否则返回1
    return !(pos_overflow || neg_overflow);
}

int main(void) {
    // 正常减法（无溢出）
    cout << "5 - 3 = " << tsub_ok(5, 3) << endl;           // 输出: 1（不溢出）
    // 正溢出
    cout << "INT_MAX - INT_MIN = " << tsub_ok(INT_MAX, INT_MIN) << endl; // 输出: 0（溢出）
    
    // 负溢出
    cout << "INT_MIN - INT_MAX = " << tsub_ok(INT_MIN, INT_MAX) << endl; // 输出: 0（溢出）
    
    return 0;
```

## 2.75

![img](https://houlir2.dpdns.org/2025/08/af26ba2b368b526c0b667af14a47ee16.png)

$$等式2.18:(x′⋅y′)\ mod\ 2^w=(x⋅y)\ mod\ 2^w$$

```c
// 2.75 unsigned_high_prod#
int signed_high_prod(int x, int y) {//取出有符号数的高w位（32）
	int64_t mul = (int64_t) x * y;
	return mul >> 32;
}
// 求无符号数的高w位
unsigned unsigned_high_prod(unsigned x, unsigned y) {
	int sig_x = x >> 31;//获取x的符号，0或者1
	int sig_y = y >> 31;//获取y的符号
	int signed_prod = signed_high_prod(x, y);
	return signed_prod + x * sig_y + y * sig_x;
}

int main(void) {
    // x正，y正
    cout << "unsigned_high_prod(0x80000000, 0x80000000) = " 
        << unsigned_high_prod(0x80000000u, 0x80000000u) << endl; 
    // 预期：0x80000000 * 0x80000000 = 0x4000000000000000，高32位为0x40000000（十进制1073741824）
    return 0;
}
```

## 2.76

![img](https://houlir2.dpdns.org/2025/08/f71c794a2f0916b638c9eb1a59f7967c.png)

```c

```

## 2.77

![img](https://houlir2.dpdns.org/2025/08/cf4baf71818ade9812b20d448294f4ae.png)

```c

```

## 2.78

![img](https://houlir2.dpdns.org/2025/08/13840d60a2959beedec773f74e2e29dc.png)

```c

```

## 2.79

![img](https://houlir2.dpdns.org/2025/08/3a1ebe9f0b5ed1b3e240584797e44aa4.png)

```c

```

## 2.80

![img](https://houlir2.dpdns.org/2025/08/1f9b8176a304c94cfe88af2e91901420.png)

```c

```

## 2.81

![img](https://houlir2.dpdns.org/2025/08/b17ada517c2765c2b0160e3474a3181b.png)

![img](https://houlir2.dpdns.org/2025/08/0bc43222b018a52e31bc14ec3ecae31a.png)

```c

```

## 2.82

![img](https://houlir2.dpdns.org/2025/08/ded39c8622dfea3afd2c0968ee8a61ae.png)

```c

```

## 2.83

![img](https://houlir2.dpdns.org/2025/08/7140d32ab1168c228067b2def7564591.png)

```c

```

## 2.84

![img](https://houlir2.dpdns.org/2025/08/c204929d6f0e8933a11ca2d958472eab.png)

```c

```

## 2.85

![img](https://houlir2.dpdns.org/2025/08/031b92dbcc65c634044c15d991423a20.png)

```c

```

## 2.86

![img](https://houlir2.dpdns.org/2025/08/d1d0ceadcd655a162f511d0945342caf.png)
![img](https://houlir2.dpdns.org/2025/08/340122e72356dd4006f5b405cc446999.png)

```c

```

## 2.87

![img](https://houlir2.dpdns.org/2025/08/55eedd5e7e948677ca3c297c7a791352.png)

```c

```

## 2.88

![img](https://houlir2.dpdns.org/2025/08/13cfdeb4553607ba8442b59675a75f8f.png)
![img](https://houlir2.dpdns.org/2025/08/1f826671883b8b048891d4dab3d08a2f.png)

```c

```

## 2.89

![img](https://houlir2.dpdns.org/2025/08/59adef8de3deebc313ae4b32c1144aa4.png)

```c

```

## 2.90

![img](https://houlir2.dpdns.org/2025/08/eb0dcbdfd9919dff99783c7d37f62c21.png)
![img](https://houlir2.dpdns.org/2025/08/58e6ed0dee022c7f15c56cadd34ae418.png)

```c

```

## 2.91

![img](https://houlir2.dpdns.org/2025/08/b25372b1f922748d351cfa244d443c63.png)

```c

```

## 2.92

![img](https://houlir2.dpdns.org/2025/08/cbb3553b1c5b07b8ec72bed6137e5265.png)

```c

```

## 2.93

![img](https://houlir2.dpdns.org/2025/08/9e8f86845bc3e2cfe2dc7beb25682c92.png)

```c

```

## 2.94

![img](https://houlir2.dpdns.org/2025/08/b1e18fdd1ff9740d2fa1170a2f3b1420.png)

```c

```

## 2.95

![img](https://houlir2.dpdns.org/2025/08/3cb7e6001c782029bf16a16f93ad585b.png)

```c

```

## 2.96

![img](https://houlir2.dpdns.org/2025/08/5fc7bec20f5c3c6527b74d11a94b6da6.png)

```c

```

## 2.97

![img](https://houlir2.dpdns.org/2025/08/d453653b7fad1416681d73f29a8ba715.png)

```c

```

## 总结

代码已上传github[深入理解计算机系统第三版第二章作业题答案](https://github.com/agelessman/csapp-3e-solutions/tree/master/第二章答案)
如有错误之处，还请指正啊。。。
