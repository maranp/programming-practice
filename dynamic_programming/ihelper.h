#pragma once

#include <algorithm>

#include <numeric>
// partial_sum

#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::endl;

auto cprint = [](auto const & c) {
  std::for_each(begin(c), end(c), [](auto const &e) {
    cout << e << " ";
  });
  cout << '\n';
};
