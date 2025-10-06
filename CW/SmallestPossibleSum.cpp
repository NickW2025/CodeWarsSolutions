//
// Created by Nick on 05/10/2025.
//

// https://www.codewars.com/kata/52f677797c461daaf7000740/train/cpp

#include <algorithm>
#include <vector>

using std::size_t, std::vector;
using ull = unsigned long long;

void bubbleToPosition(vector<ull>& vector, size_t index);

ull solution(const vector<ull>& arr) {
  if (arr.empty()) return 0;
  if (arr.size() == 1) return arr[0];

  vector<ull> working_vector = arr;
  std::sort(working_vector.begin(), working_vector.end());
  working_vector = vector(working_vector.begin(),
    std::unique(working_vector.begin(), working_vector.end()));

  while (working_vector.size() > 1) {
    size_t max = working_vector.size()-1;
    const ull temp = working_vector[max] % working_vector[max-1];
    working_vector[max] = ((temp > 0) ? temp : working_vector[max-1]);
    bubbleToPosition(working_vector, max);
  }
  return working_vector[0] * arr.size();
}

void bubbleToPosition(vector<ull>& vector, size_t index) {
  while (index >= 1 && vector[index] <= vector[index-1]) {
    if (vector[index-1] == vector[index]) {
      vector.erase(vector.begin() + index);
      break;
    }
    std::swap(vector[index], vector[index-1]);
    --index;
  }
  return;
}