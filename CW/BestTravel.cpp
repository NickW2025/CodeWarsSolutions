//
// Created by Nick on 26/09/2025.
//

// https://www.codewars.com/kata/55e7280b40e1c4a06d0000aa/train/cpp




//BestTravel.h

#include <iostream>
#include <vector>

using std::vector;
using uint = std::size_t;

class BestTravel {
  public:
    static int chooseBestSum(int t, int k, const vector<int>& ls);
    static void testGetSubsets();
    static void printToConsole(const vector<vector<int>>& vecvec);
    static vector<vector<int>> getSubsets(int subset_size, const vector<int>& set);
};




//BestTravel.cpp

vector<vector<int>>
BestTravel::getSubsets(const int subset_size, const vector<int>& set) {
  //catch invalid size input
  if (subset_size <= 0 || subset_size > set.size()) {
    throw std::invalid_argument("Invalid subset size");
  }

  //base case for size 1
  if (subset_size == 1) {
    vector<vector<int>> result;
    for (int i: set) {
      result.push_back({i});
    }
    return result;
  }

  //TODO: implement general case for size > 1
}

int BestTravel::chooseBestSum(const int t, const int k, const vector<int>& ls) {
  static uint size = ls.size();
  if (k > size) return -1;
  //TODO: implement this
}

void BestTravel::printToConsole(const vector<vector<int>>& vecvec) {
  //TODO: output looks atrocious, should be improved
  std::cout << "Vector[\n";
  for (auto& vec: vecvec) {
    std::cout << "Vector(";
    for (const auto i: vec) {
      std::cout << i << ", ";
    }
    std::cout << ")\n";
  }
  std::cout << "]\n";
}

void BestTravel::testGetSubsets() {
  printToConsole(getSubsets(1, {3, 7, 2, 5}));
}



