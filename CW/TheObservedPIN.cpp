//
// Created by Nick on 04/10/2025.
//

// https://www.codewars.com/kata/5263c6999e0f40dee200059d/cpp

#include <string>
#include <vector>

using std::string;
using std::vector;

const vector<vector<char>> ADJACENT_KEYS {
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

vector<string> constructOutput(const char c_in) {
  vector<string> v_out{};
  for (const char adj_key: ADJACENT_KEYS[c_in-'0']) {
    string str{};
    str.append(1, adj_key);
    v_out.push_back(str);
  }
  return v_out;
}

vector<string> addCharToOutput(const vector<string>& v_in, const char c_in) {
  vector<string> v_out{};
  for (const auto& str_in: v_in) {
    for (const char adj_key: ADJACENT_KEYS[c_in-'0']) {
      string str = str_in;
      str.append(1, adj_key);
      v_out.push_back(str);
    }
  }
  return v_out;
}

vector<string> processChar(const vector<string>& v_in, const char c_in){
  if (v_in.empty()) return constructOutput(c_in);
  else return addCharToOutput(v_in, c_in);
}

vector<string> get_pins(const string& observed) {
  vector<string> possible_pins{};
  for (const char c : observed) {
    possible_pins = processChar(possible_pins, c);
  }
  return possible_pins;
}