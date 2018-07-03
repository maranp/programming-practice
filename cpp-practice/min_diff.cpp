/*
 * min_diff.cpp
 *
 *  Created on: 27-Jun-2018
 *      Author: maran
 */

#include "ihelper.hpp"
#include <numeric>

int main() {
  vector<int> vi {10, 20, 30, 100, 200, 300, 1000, 1005};
  auto min = std::numeric_limits<int>::max();
  return std::inner_product(begin(vi), end(vi) - 1, next(begin(vi)), min,
      [](auto accum, auto diff) {
        return diff < accum ? diff : accum;
      },
      [](auto e1, auto e2) {
        return e2 - e1; // 20 -10, 30 - 20, 100 - 30, etc
      });

}


