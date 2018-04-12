/*
 * rough.cpp
 *
 *  Created on: 12-Apr-2018
 *      Author: maran
 */

#include "ihelper.h"

#include <typeinfo>
#include <cxxabi.h>

#include <memory>

class S {
public:
  S(std::initializer_list<int> list_) : list {list_} {}

  auto begin() const {
    return std::begin(list);
  }
  auto end() const {
    return std::end(list);
  }
private:
  std::initializer_list<int> list;
};

int main() {
  // using Type = decltype( {1, 2, 3});
  // std::initializer_list<int> list {1, 2, 3};
  //auto list {1, 2, 3}; // doesn't compile: direct list initialization with auto is prohibited
  auto list = {1, 2, 3}; // copy list initialization with auto is allowed
  using Type = decltype(list);
  cout << type_print_raw<Type>()<< endl;
  cout << type_print_pretty<Type>()<< endl;

  S s {1, 2, 3};
  for (auto e : s) {
    cout << e << '\n';
  }

  // does not compiler
  // the liust passed is actually const std::unique_ptr<int>[3]
  // so, the elements cannot be moved into vector. so, copy constructor of unique_ptr is called but copy const. is deleted
//  std::vector<std::unique_ptr<int>> vup {
//    std::make_unique<int>(1),
//    std::make_unique<int>(2),
//    std::make_unique<int>(3)
//  };

  return 0;
}


