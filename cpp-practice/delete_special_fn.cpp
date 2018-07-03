/*
 * delete_special_fn.cpp
 *
 *  Created on: 28-Jun-2018
 *      Author: maran
 */

#include "ihelper.hpp"

struct Foo {
private:
  Foo() = delete;
  //Foo() = default;
  //Foo() {}
};

int main() {
  Foo f {};
  //Foo f1;
  return 0;
}


