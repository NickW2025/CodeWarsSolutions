//
// Created by Nick on 04/10/2025.
//

// https://www.codewars.com/kata/52ec24228a515e620b0005ef/train/cpp

#include <iostream>
#include <map>
#include <stdexcept>

using std::map;
using std::pair;
using ull = unsigned long long;
using uint = unsigned int;

//
// getPartitionNumber(n,m) implements this recursive formula:
// p(n, m) = p(n-m, m) + p(n, m-1)
// which gives the number of partitions of n
// into summands that are less than or equal to m.
//
ull getPartitionNumber(int n, int m) {
  static map<pair<int, int>, ull> cache{};
  // base cases
  if (n < 1) return 0;
  if (m < 1) return 0;
  if (m == 1) return 1;
  if (n == 1) return 1;

  try {
    // cache lookup to avoid unnecessary computation
    return cache.at(std::make_pair(n, m));
  }
  catch (std::out_of_range& e) {
    // in case of cache miss, recursively calculate the target number
    ull result = getPartitionNumber(n-m, m) + getPartitionNumber(n, m-1);

    // before returning, cache the calculated number for future reuse
    cache.insert({std::make_pair(n, m), result});
    return result;
  }
}

ull exp_sum(const uint n) {
  return getPartitionNumber(static_cast<int>(n+1), static_cast<int>(n+1));
}