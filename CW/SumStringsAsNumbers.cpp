//
// Created by Nick on 25/09/2025.
//

// https://www.codewars.com/kata/5324945e2ece5e1f32000370/train/cpp

#include <algorithm>
#include <sstream>
#include <string>

using std::string;
using std::stringstream;

string sum_strings(const string& a, const string& b) {
  string a_rev = a;
  std::reverse(a_rev.begin(), a_rev.end());
  string b_rev = b;
  std::reverse(b_rev.begin(), b_rev.end());

  string small{};
  string large{};
  if (a_rev.size() > b_rev.size()) {
    small = std::move(b_rev);
    large = std::move(a_rev);
  } else {
    small = std::move(a_rev);
    large = std::move(b_rev);
  }
  small.append(large.size() - small.size(), '0');

  stringstream result_stream{};
  char carry{0};
  for (int i = 0; i < small.size(); i++) {
    const char x = static_cast<char>(small[i] - 48);
    const char y = static_cast<char>(large[i] - 48);
    char res = static_cast<char>(x + y + carry);
    if (res > 9) {
      res -= 10;
      carry = 1;
    }
    else carry = 0;
    res += 48;
    result_stream << res;
  }

  if (carry > 0) {
    carry += 48;
    result_stream << carry;
  }

  string result_string = result_stream.str();
  std::reverse(result_string.begin(), result_string.end());
  return result_string;
}