/*
 * string_things.cpp
 *
 *  Created on: 25-Jun-2018
 *      Author: maran
 */

#include "ihelper.hpp"
#include <cstdlib>

void * operator new(size_t n) {
  cout << "[allocating " << n << " bytes] ";
  return malloc(n);
}

void operator delete(void *p) throw() {
  free(p);
}

int main() {
  // 32 with libstdc++
  // 24 with libc++
  cout << sizeof(string) << endl;
  cout << sizeof(string("hello")) << endl;

  for (auto i = 0; i < 64; i++) {
    cout << i << " " << string(i, '=') << endl;
  }

  return 0;
}



