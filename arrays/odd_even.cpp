/*
 * odd_even.cpp
 *
 *  Created on: 27-Mar-2018
 *      Author: maran
 */

#include <algorithm>
#include <vector>
#include "print.h"


int main() {
  std::vector<int> vi {23, 345, -234, 45, 89, 24};
  std::vector<int> vi2 {vi};
  std::partition(begin(vi), end(vi), [](int e) {
    // is even?
    return (e & 1) == 0;
  });
  print(vi);

  // manual implementation
  auto even = 0;
  auto odd = vi2.size() - 1;
  while (even < odd) {
    if (vi2[even] % 2 != 0) {
      // swap if even not found and decrement odd
      std::swap(vi2[even], vi2[odd]);
      // we are not decrementing even because,
      // the swapped vi2[odd] might contain odd
      // so do not incremen even until we are sure that
      // we found even.
      odd--;
    } else {
      even++;
    }
  }
  print(vi2);
}
