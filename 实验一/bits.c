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
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

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

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

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
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
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
/* Copyright (C) 1991-2014 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses ISO/IEC 10646 (2nd ed., published 2011-03-15) /
   Unicode 6.0.  */
/* We do not support C11 <threads.h>.  */
/* 
 *   lsbZero - set 0 to the least significant bit of x 
 *   Example: lsbZero(0x87654321) = 0x87654320
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 1
 */
int lsbZero(int x) {
  x=(x>>1)<<1;
  return x;
}
/* 
 * byteNot - bit-inversion to byte n from word x  
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByteNot(0x12345678,1) = 0x1234A978
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
/* n<<3 means n*8,0xff<<(n<<3) means puting the n bit with 0xff to achieve negation*/ 
int byteNot(int x, int n) {
  x=x^(0xff<<(n<<3));	
  return x;
}
/* 
 *   byteXor - compare the nth byte of x and y, if it is same, return 0, if not, return 1

 *   example: byteXor(0x12345678, 0x87654321, 1) = 1

 *			  byteXor(0x12345678, 0x87344321, 2) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 2 
 */
 /* x&(0xff<<(n<<3)) achieve to get the n bits */
int byteXor(int x, int y, int n) {
  x=x&(0xff<<(n<<3));
  y=y&(0xff<<(n<<3));
  
  return !(!(x^y));	/*can't return x^y ,if x!=y,x^y!=1&x^y!=0  ,use 2 ! to get logical answer*/
}
/* 
 *   logicalAnd - x && y
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
 /* if one of x,y is 0,!x|!y is 1,!1=0
  * if both of x,y are 0, !x|!y is 1, !1=0
  * if neither of x,y is 0, !x|!y is 0, !0=1
  */
int logicalAnd(int x, int y) {
  return !(!x|!y);	/*the answer is 0 or 1, but & is 0 or else  */
}
/* 
 *   logicalOr - x || y
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalOr(int x, int y) {
  
  return !(!x&!y);	/*like the logicalAnd*/
}
/* 
 * rotateLeft - Rotate x to the left by n
 *   Can assume that 0 <= n <= 31
 *   Examples: rotateLeft(0x87654321,4) = 0x76543218
 *   Legal ops: ~ & ^ | + << >> !
 *   Max ops: 25
 *   Rating: 3 
 */
 /* here we use 0x7fffffff to achieve rolling, because 0x7fffffff won't be expanded with 0 in high bits when right shift */
int rotateLeft(int x, int n) {
  int xh,xl;
  int offset=(1<<31)+(~1)+1;	/*0x7fffffff is illegal constant,  0x80000000-1=0x7fffffff*/
  int m=33+(~n);
  xl=x<<n;;
  xh=(x>>m)&(offset>>(32+(~n)));	/*the bits offset rols =m-1 to make sure get the n bits roled out */
  return xl|xh;
}
/*
 * parityCheck - returns 1 if x contains an odd number of 1's
 *   Examples: parityCheck(5) = 0, parityCheck(7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
/*两两分组之后在异或*/
int parityCheck(int x) {
  x ^=x>>16;	/*0~16位保留1的总个数的奇偶与v中的1的总个数的奇偶相同*/
  x ^=x>>8;	/*0~8位保留1的总个数的奇偶与0~16中1的总个数的奇偶相同*/
  x ^=x>>4;	/*0~4位保留1的总个数的奇偶与0~4中1的总个数的奇偶相同*/
  x ^=x>>2;	/*0~2位保留1的总个数的奇偶与0~2中1的总个数的奇偶相同*/
  x ^=x>>1;	/*0~1位保留1的总个数的奇偶与0~1中1的总个数的奇偶相同*/
  return x&1;
}
/*
 * mul2OK - Determine if can compute 2*x without overflow
 *   Examples: mul2OK(0x30000000) = 1
 *             mul2OK(0x40000000) = 0
 *         
 
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 2
 */
int mul2OK(int x) {
  int y=(x>>31)&0x1;	/*sign before mul*/
  int z;
  x=x<<1;
  z=(x>>31)&0x1;	/*sign after mul*/
  return y^z^1;	/*if y!=z,overflow, can't use !*/
}
/*
 * mult3div2 - multiplies by 3/2 rounding toward 0,
 *   Should exactly duplicate effect of C expression (x*3/2),
 *   including overflow behavior.
 *   Examples: mult3div2(11) = 16
 *             mult3div2(-9) = -13
 *             mult3div2(1073741824) = -536870912(overflow)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int mult3div2(int x) {
  int offset;
  x=(x<<1)+x;	/* x=x*3 */ 
  offset=0x1&(x>>31);	/* if x<0, we should +(2^k - 1),then shift, x>>31&0x1 is to make sure shift when x<0 */
  x= (x+offset)>>1;
  return x;
}
/* 
 * subOK - Determine if can compute x-y without overflow
 *   Example: subOK(0x80000000,0x80000000) = 1,
 *            subOK(0x80000000,0x70000000) = 0, 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
 /* the result overflows when the two operators' sign is the same, but the result is not the same */
int subOK(int x, int y) {
  int result=x+(~y)+1;
  int signx=!(!(x>>31));	/* sign of x*/
  int signy=!(!(y>>31));	/* sign of -y */
  int sign=!(!(result>>31));	/*sign of x-y */
  return !((signx^signy)&(signx^sign));	/*signx!=signy&&signx!=sign overflow*/
}
/* 
 * absVal - absolute value of x
 *   Example: absVal(-1) = 1.
 *   You may assume -TMax <= x <= TMax
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int absVal(int x) {
  int sign=x>>31;
  return (x^sign)+(sign&0x1);	/*if x<0,sign=0xffffffff,x^s=~x;if x>0,sign=0,x^s=x; sign&0x1= 1(x<0) or 0(x>=0)*/
}
/* 
 * float_abs - Return bit-level equivalent of absolute value of f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument..
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
 /* e is the exponent of uf, m is the mantissa and f is |uf|
  * ~(1<<31) is the number the 0 bit is 0 and the others are 1
  * we should pay more attention to the NaN  
  */
unsigned float_abs(unsigned uf) {
  int e=(uf&0x7f800000)>>23;
  unsigned f=uf&(~(1<<31));
  int m=uf&0x7fffff;
  if(e==0xff&&m!=0)	/*if uf==NaN,return uf*/
	return uf;
  else 
  	return f;
}
/* 
 * float_f2i - Return bit-level equivalent of expression (int) f
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
 /* e is the exponent of uf, m is the mantissa with the hidden 1, sign is the sign and offset is the number after shifting with mantissa
  * if e < 127, 0<uf<1 , the result is 0 after (int)f
  * if e >158, the exponent of uf is 31. The result must overflow after type casting because the max num of int is 2^31
  * so in this time, we should return 0x80000000
  * if 127<=e<=158, m need to shift right with 23-(e-127)=150-e bits  because we just return the interger part
  * so if 127<=e<=150, we return m>>(150-e)
  * if 150<e<=158, we return m>>(e-150) ps:traction of the interger part of float when normalization
  */
int float_f2i(unsigned uf) {
  int e=((uf&(0xff<<23))>>23)&0xff;	/*get exponent 0x..  */
  int m=(uf&0x7fffff)^(1<<23);	
  int offset;
  int sign=(uf>>31)&0x1;
  if(e<127)
	return 0;	/*uf=0.***  */
  else if(e>158)
	return 1<<31;	/* e>158-127=31 overflow int*/
  else if(e<=150)		
  	offset=m>>(150-e);
  else 
	offset=m>>(e-150);
  if(sign)
	offset=~offset+1;
 return offset;
}
