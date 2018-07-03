/*
 * std_ref.cpp
 *
 *  Created on: 30-Jun-2018
 *      Author: maran
 */

#include "ihelper.hpp"
#include <functional>

void print(int i) {
  cout << i << endl;
}

void refprint(int& i) {
  cout << i << endl;
}

int main() {
  int i = 10;
  auto f1 = std::bind(print, i);
  auto f2 = std::bind(print, std::ref(i));

  i = 20;

  f1();
  f2();

  i = 10;
  auto f3 = std::bind(refprint, i);
  auto f4 = std::bind(refprint, std::ref(i));

  i = 20;

  f3();
  f4();
}


