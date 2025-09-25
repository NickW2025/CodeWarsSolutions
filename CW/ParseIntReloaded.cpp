//
// Created by Nick on 24/09/2025.
//

// https://www.codewars.com/kata/525c7c5ab6aecef16e0001a5/train/cpp

#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using std::vector;
using std::string;
using std::stringstream;
using std::unordered_map;

unordered_map<string, long> value_map {
   {"one", 1}, {"three", 3}, {"four", 4}, {"two", 2}
  ,{"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}
  ,{"nine", 9}, {"ten", 10}, {"eleven", 11}, {"twelve", 12}
  ,{"thirteen", 13}, {"fourteen", 14}, {"fifteen", 15}, {"sixteen", 16}
  ,{"seventeen", 17}, {"eighteen", 18}, {"nineteen", 19}, {"twenty", 20}
  ,{"thirty", 30}, {"forty", 40}, {"fifty", 50}, {"sixty", 60}
  ,{"seventy", 70}, {"eighty", 80}, {"ninety", 90}
};

long parse_hyphenated(const string& number) {
  string first{};
  string second{};
  string* target = &first;
  for (char c: number) {
    if (c != '-') target->append(1, c);
    else target = &second;
  }
  return value_map[first] + value_map[second];
}

bool is_hyphenated(const string& number) {
  for (char c: number) {
    if (c == '-') return true;
  }
  return false;
}

long parse_value(const string& number) {
  if (is_hyphenated(number)) return parse_hyphenated(number);
  return value_map[number];
}

vector<string> tokenize(const string& str) {
  stringstream ss(str);
  vector<string> tokens{};
  string word{};
  while (true) {
    word.clear();
    ss >> word;
    if (word.empty()) break;
    tokens.push_back(word);
  }
  return tokens;
}

long parse_int(const string& number) {
  if (number == "zero") return 0;
  long result = 0;
  long buffer = 0;
  auto tokens = tokenize(number);

  for (auto& token: tokens) {
    if (token == "million") {
      return 1000000;
    }
    if (token == "hundred") {
      buffer *= 100;
      continue;
    }
    if (token == "thousand") {
      result += buffer * 1000;
      buffer = 0;
      continue;
    }
    if (token != "and") {
      buffer += parse_value(token);
    }
  }

  result += buffer;
  return result;
}

void test() {
  std::cout << parse_hyphenated("forty-six") << std::endl;
}