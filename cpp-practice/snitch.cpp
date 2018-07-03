/*
 * snitch..cpp
 *
 *  Created on: 25-Jun-2018
 *      Author: maran
 *      https://shaharmike.com/cpp/rvo/
 */

#include "ihelper.hpp"

class Snitch {
public:
  Snitch() {
    cout << "ctor\n";
  }

  ~Snitch() {
    cout << "dtor\n";
  }

  Snitch(Snitch const&) {
    cout << "copy ctor\n";
  }

  Snitch(Snitch&&) {
    cout << "move ctor\n";
  }

  Snitch& operator=(Snitch const&) {
    cout << "copy assignment\n";
    return *this;
  }

  Snitch& operator=(Snitch&&) {
    cout << "move assignment\n";
    return *this;
  }
};

// rvo is guaranteed in c++17
// even with -fno-elide-constructors, move ctor is not called
// to contrast build with c++11 and see the output (one default ctor and 2 move ctors)
Snitch rvo() {
  return Snitch {};
}

// named rvo is not guaranteed in c++17
// with -fno-elide-constructors, a move constructor and its dtor are invoked
// (one default ctor and 1 move ctor)
Snitch named_rvo() {
  Snitch s = Snitch {};
  return s;
}

// copy elision is guaranteed in c++17
// but not in c++11. with -fno-elide-constructors,
// one default ctor and 1 move ctor are called
void copy_elide(Snitch s) {

}

struct Wrapper {
  Snitch  s;
};

// cannot do rvo in c++17
// 1 ctor and 1 move ctor
// in this case, Snitch cannot be non-movable
Snitch get_from_wrapper() {
  return Wrapper().s;
}

int main() {
  // Snitch s {};

  // Snitch s1 = rvo();
  // Snitch s1 = named_rvo();

  // copy_elide(Snitch());


//  o/p of next 2 lines with c++17
//  ctor
//  ctor
//  move assignment
//  dtor
//  dtor
//  Snitch s1 = rvo();
//  s1 = rvo();


  Snitch s1 = get_from_wrapper();

  return 0;
}
