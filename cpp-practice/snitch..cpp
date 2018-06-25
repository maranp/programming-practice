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
  }

  Snitch& operator=(Snitch&&) {
    cout << "move assignment\n";
  }
};

int main() {
  Snitch s();

  return 0;
}
