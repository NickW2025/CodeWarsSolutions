//
// Created by Nick on 12/10/2025.
//

// https://www.codewars.com/kata/5254ca2719453dcc0b00027d/train/cpp

#include <algorithm>
#include <string>
#include <vector>

using std::string, std::vector, std::sort, std::next_permutation;

vector<string> permutations(string s) {
  if (s.empty()) return {};

  sort(s.begin(), s.end());
  vector<string> result{};

  do result.push_back(s);
    while (next_permutation(s.begin(), s.end()));

  return result;
}

// using std::next_permutation for this problem feels like cheating...