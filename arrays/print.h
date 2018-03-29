#pragma once

#include <iostream>

using std::cout;
using std::endl;

template <typename ContainerT>
void print(ContainerT const & c) {
  for (auto const & e : c) {
    std::cout << e << ' ';
  }
  std::cout << '\n';
}
