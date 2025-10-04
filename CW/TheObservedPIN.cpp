//
// Created by Nick on 04/10/2025.
//

// https://www.codewars.com/kata/5263c6999e0f40dee200059d/cpp

#include <string>
#include <vector>

using std::string;
using std::vector;

const vector<vector<char>> adjacent_keys{
  {'0', '8'},
  {'1', '2', '4'},
  {'1', '2', '3', '5'},
  {'2', '3', '6'},
  {'1', '4', '5', '7'},
  {'2', '4', '5', '6', '8'},
  {'3', '5', '6', '9'},
  {'4', '7', '8'},
  {'5', '7', '8', '9', '0'},
  {'6', '8', '9'}
};

vector<string> addDigit(const vector<string>& v_in, const char c_in) {
  vector<string> v_out{};
  if (v_in.empty()) {
    for (const char possible: adjacent_keys[c_in-'0']) {
      string str_working{};
      str_working += possible;
      v_out.push_back(str_working);
    }
  }
  else {
    for (const auto& str_in: v_in) {
      for (const char possible: adjacent_keys[c_in-'0']) {
        string str_working = str_in;
        str_working += possible;
        v_out.push_back(str_working);
      }
    }
  }
  return v_out;
}

vector<string> get_pins(const string& observed) {
  vector<string> possible_pins{};
  for (const char c : observed) {
    possible_pins = addDigit(possible_pins, c);
  }
  return possible_pins;
}