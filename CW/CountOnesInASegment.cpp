//
// Created by Nick on 06/10/2025.
//

// https://www.codewars.com/kata/596d34df24a04ee1e3000a25/train/cpp

#include <cmath>
#include <iostream>
using ll = long long;

ll sumOnesInFirstBinaryNums(int num);
int logBaseTwo(int num);
int powTwo(int num);

ll countOnes (const int left, const int right) {
  return sumOnesInFirstBinaryNums(right+1) - sumOnesInFirstBinaryNums(left);
}

ll sumOnesInFirstBinaryNums(int num) {
  if (num < 2) return 0;
  if (num == 2) return 1;

  const int log = logBaseTwo(num);
  const int remaining = num - powTwo(log);

  if (remaining == 0)
    return 2 * sumOnesInFirstBinaryNums(powTwo(log-1)) + powTwo(log-1);
  else
    return sumOnesInFirstBinaryNums(powTwo(log)) + sumOnesInFirstBinaryNums(remaining) + remaining;
}

int logBaseTwo(int num) {
  if (num == 0) throw std::invalid_argument("Logarith,0m of 0 is undefined.");
  if (num < 0) num = -num;
  if (num == 1) return 0;
  return logBaseTwo(num / 2) + 1;
}

int powTwo (int num) {
  if (num == 0) return 1;
  if (num < 0) num = -num;
  if (num == 1) return 2;
  return 2 * powTwo(num - 1);
}

/*
 *
 *
 *  00000 0   S(1) = 0
 *  00001 1   S(2) = 1    //Block 1
 *
 *  00010 1   S(3) = 2
 *  00011 2   S(4) = 4    //Block 2
 *
 *  00100 1   S(5) = 5
 *  00101 2
 *  00110 2
 *  00111 3   S(8) = 12   //Block 3
 *
 *  01000 1   S(9) = 13
 *  01001 2
 *  01010 2
 *  01011 3
 *  01100 2
 *  01101 3
 *  01110 3
 *  01111 4   S(16) = 32  //Block 4
 *
 *  10000 1   S(17) = 33
 *  10001 2
 *  10010 2
 *  10011 3
 *  10100 2
 *  10101 3
 *  10110 3
 *  10111 4
 *  11000 2
 *  11001 3
 *  11010 3
 *  11011 4
 *  11100 3
 *  11101 4
 *  11110 4
 *  11111 5   S(32) = 80  //Block 5
 *
 *  ...       S(2^n) = 2*S(2^n-1) + 2^(n-1)   //Block n
 *
 *
 */