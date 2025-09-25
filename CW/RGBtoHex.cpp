//
// Created by Nick on 24/09/2025.
//

// https://www.codewars.com/kata/513e08acc600c94f01000001/train/cpp

#include <sstream>
#include <string>

std::string toHex(int i) {
  if (i < 0) i = 0;
  if (i > 255) i = 255;

  std::stringstream ss{};
  ss << std::uppercase << std::hex << i/16 << i%16;
  return ss.str();
}

std::string rgb_to_hex(int r, int g, int b) {
  return toHex(r) + toHex(g) + toHex(b);
}