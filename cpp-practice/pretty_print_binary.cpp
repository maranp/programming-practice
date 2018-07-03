/*
 * pretty_print_binary.cpp
 *
 *  Created on: 28-Jun-2018
 *      Author: maran
 */

#include "ihelper.hpp"
#include <bitset>

int main() {
  auto bs_str {std::bitset<32> {8}.to_string()};
  cout << bs_str << endl;
  cout << bs_str.erase(0, bs_str.find_first_not_of('0')) << endl;
}


