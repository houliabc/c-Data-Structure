/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
//1
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
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  return 1 << 31;
}
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
  int zero = x >> 6;
  int first = 0x30 ^ (x & 0xf0);  // 相同则为0
  // I can use 0xF minus
  int second = (x & 0xf);  // 截取低4位
  int minus = (second + ~0x9) >> 31;   // 该第四位满足条件：second - 'a' < 0成立，否则就不符合
  return (!zero & !first & !!minus);
}
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
// 运用0的性质，0的相反数还是0，按位或得到的值还是0（最高位也为0）
// 其他值与相反数按位或得到的最高位为1（值与相反数总有一个是负数），但如果右移后就是-1
  int first = x >> 31;
  int two = (~x + 1) >> 31;  // 如果符号位为0，那这里会触发算数右移，结果是-1
  return 1 + (first | two);  // 加1是为了使原本的值域【-1，0】转变为【0，1】，才能符合题目
}
// 使用补码时最少需要多少比特位
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
// 假设1在高1位中，则x=1,则该补码至少需要16+8+4+2+1+1位。
// 最后不要忘记符号位，再加上1。

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
  int E = exp + ~(126); 
  frac = frac | 1 << 23;

  // 判断超出范围的情况
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
    return 2;
}
