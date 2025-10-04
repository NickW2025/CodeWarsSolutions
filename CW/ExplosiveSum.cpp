//
// Created by Nick on 04/10/2025.
//

// https://www.codewars.com/kata/52ec24228a515e620b0005ef/train/cpp

#include <iostream>
#include <map>
#include <set>
#include <stdexcept>

using std::map;
using std::set;
using std::multiset;
using ull = unsigned long long;
using uint = unsigned int;

set<multiset<uint>> getPartitions(const uint number) {
  static map<uint, set<multiset<uint>>> cache{};

  // base cases - immediate result
  if (number == 0) return {};
  if (number == 1) return {{1}};

  // check cache to avoid unnecessary repetition
  try {
    return cache.at(number);
  } catch (const std::out_of_range& e) {}

  // general case - recursion
  //TODO: implement this
  set<multiset<uint>> final_result{};
  set<multiset<uint>> recursion_result = getPartitions(number - 1);

  // add computed result to cache for future reuse
  cache.insert({number, final_result});
  std::cout << "finished computation for " << number << std::endl;
  return final_result;
}

ull exp_sum(const uint n) {
  return getPartitions(n).size();
}