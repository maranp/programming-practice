/*
 * plus_one.cpp
 *
 *  Created on: 14-Apr-2018
 *      Author: maran
 */

#include "../ihelper.h"

void plus_one() {
  vector<int> a {9, 9, 9, 9};
  cprint(a);
  a.back()++;

  for (auto i = a.size() - 1; i > 0 && a[i] == 10; i--) {
    a[i] = 0;
    a[i - 1]++;
  }
  if (a[0] == 10) {
    a[0] = 0;
    a.insert(begin(a), 1);
  }
  cprint(a);
}

int main() {
  plus_one();
}



