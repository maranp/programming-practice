/*
 * ref_cref.cpp
 *
 *  Created on: 25-Jun-2018
 *      Author: maran
 */

#include "ihelper.hpp"

#include <functional>

void f(int& n1, int& n2, int const& n3) {
  cout << "in f: " << n1 << " " << n2 << " " << n3 << endl;
  n1++;
  n2++;
  // n3++;
}

int main() {
  int n1 = 1, n2 = 2, n3 = 3;
  std::function<void ()> bound_f = std::bind(f, n1, std::ref(n2), std::cref(n3));

  n1 = 10;
  n2 = 11;
  n3 = 12;

  cout << "before bound_f: " << n1 << " " << n2 << " " << n3 << endl;
  bound_f();
  cout << "after bound_f: " << n1 << " " << n2 << " " << n3 << endl;
}



