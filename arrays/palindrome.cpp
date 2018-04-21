/*
 * palindrome.cpp
 *
 *  Created on: 21-Apr-2018
 *      Author: maran
 */

#include "../ihelper.h"
#include <numeric>

int main() {
  // string p {"11011"};
  //string p {"110011"};
  string p {"110111"};
  cout << std::boolalpha <<
  // std::inner_product(begin(p), end(p), rbegin(p), true, std::logical_and<>(), std::equal_to<>())
  std::inner_product(begin(p), begin(p) + p.length() / 2, rbegin(p), true, std::logical_and<>(), std::equal_to<>())
  << endl;
}


