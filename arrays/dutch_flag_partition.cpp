/*
 * dutch_flag_partition.cpp
 *
 *  Created on: 27-Mar-2018
 *      Author: maran
 */

#include "header.h"
#include "print.h"

void dutch_flag_partition() {
  vector<int> vi {0, 1, 2, 0, 2, 1, 1};

  auto p = vi[0];
  std::partition(begin(vi), end(vi), [p](int e) {
    return e < p;
  });
  print(vi);
}

int main() {
  dutch_flag_partition();
}
