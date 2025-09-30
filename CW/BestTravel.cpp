//
// Created by Nick on 26/09/2025.
//

// https://www.codewars.com/kata/55e7280b40e1c4a06d0000aa/train/cpp

#include <algorithm>
#include <set>
#include <stdexcept>
#include <vector>

using std::vector;
using std::multiset;
using std::set;

class BestTravel {
  public:
    static int chooseBestSum(int t, int k, const vector<int>& ls);
    static set<int> getSubsetSums(int subset_size, const multiset<int>& input_set);
};

set<int> BestTravel::getSubsetSums(int subset_size, const multiset<int>& input_set) {
  //catch invalid inputs
  if (subset_size <= 0) {
    throw std::runtime_error("INVALID INPUT");
  }

  if (subset_size > input_set.size()) return set<int>{};

  //base case: subset_size 1
  if (subset_size == 1) return set<int> {input_set.begin(), input_set.end()};

  //general case: subset_size > 1
  multiset<int> working_copy = input_set;
  set<int> result{};
  for (int i: input_set) {
    working_copy.erase(working_copy.find(i));
    set<int> subset_sums = getSubsetSums(subset_size-1, working_copy);
    for (const int element: subset_sums) {
      result.insert(element + i);
    }
  }
  return result;
}

int BestTravel::chooseBestSum(const int t, const int k, const vector<int>& ls) {
  if (k > ls.size()) return -1;
  if (ls.empty()) return -1;
  if (k <= 0) return -1;

  int result = -1;
  multiset<int> mset(ls.begin(), ls.end());
  auto subset_sums = getSubsetSums(k, mset);

  for (const int element: subset_sums) {
    if (element > result &&  element <= t) result = element;
  }

  return result;
}