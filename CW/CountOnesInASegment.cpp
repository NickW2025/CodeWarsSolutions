//
// Created by Nick on 06/10/2025.
//

// https://www.codewars.com/kata/596d34df24a04ee1e3000a25/train/cpp

#include <iostream>
using uint = unsigned int;;

long long sumOnesInBinaryNumsUpTo(uint num);
uint logBaseTwo(uint num);

long long countOnes ( uint left, uint right ) {
  return sumOnesInBinaryNumsUpTo(right) - sumOnesInBinaryNumsUpTo(left);
}

long long sumOnesInBinaryNumsUpTo(uint num) {
  //TODO: implement this
  return -1;
}

uint logBaseTwo(uint num) {
  if (num == 0) throw std::invalid_argument("Logarithm of 0 is undefined.");
  if (num == 1) return 0;
  return logBaseTwo(num / 2) + 1;
}

/*
 *
 *
 *  00000 0
 *  00001 1
 *
 *  00010 1
 *  00011 2
 *
 *  00100 1
 *  00101 2
 *  00110 2
 *  00111 3
 *
 *  01000 1
 *  01001 2
 *  01010 2
 *  01011 3
 *  01100 2
 *  01101 3
 *  01110 3
 *  01111 4
 *
 *  10000 1
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
 *  11111 5
 *
 *  ...
 *
 *
 */