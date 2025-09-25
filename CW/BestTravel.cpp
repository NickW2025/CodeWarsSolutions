//
// Created by Nick on 26/09/2025.
//

// https://www.codewars.com/kata/55e7280b40e1c4a06d0000aa/train/cpp

#include <iostream>
#include <vector>

using std::vector;
using uint = std::size_t;

class BestTravel {
  public:




    static vector<vector<int>>
    getSubsets(const int subset_size, const vector<int>& set) {
      //TODO: implement this
    }

    static int chooseBestSum(const int t, const int k, const vector<int>& ls) {
      static uint size = ls.size();
      if (k > size) return -1;
      //TODO: implement this
    }




};



void printToConsole(const vector<vector<int>>& vecvec) {
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

void testGetSubsets() {
  //TODO: test getSubsets() function
}