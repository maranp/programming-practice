/*
 * cons_dest_debugging.cpp
 *
 *  Created on: 21-Apr-2018
 *      Author: maran
 */

#include "../ihelper.h"

struct X {
  int val;
  void out(string const & member, int v) {
    cout << this << "->" << member << " val:" << v << endl;
  }
public:
  X() : val {0} {
    out("X()", val);
  }
  X(int v) : val {v} {
    out("X(int)", val);
  }
  // copy constructor
  X(X const &x) : val {x.val} {
    out("X(X const &)", val);
  }
  X& operator=(X const &x) {
    val = x.val;
    out("operator=(X const &)", val);
    return *this;
  }

  ~X() {
    out("~X()", val);
  }
};

X copy(X a) {
  return a;
}

X copy2(X a) {
  X aa = a;
  return aa;
}

X& ref_to(X& a) {
  return a;
}

X* make(int i) {
  // 1. one arg constructor
  X x{i};

  // copy constructor
  return new X {x};

  // 1. destructor
}

struct XX {
  X a;
  X b;
};

int main() {
  // 1. one arg. constructor
  X loc {4};

  // 2. copy. constructor
  X loc2 = loc;

  // 3. one arg. constructor
  // copy assignment operator on loc
  // 3. destructor (temporary is destroyed once assignemnt is complete)
  loc = X {5};

  // 4. one arg. constructor
  X loc3 {6};

  // ref. is passed and ref. ,is returned. No object instantia,tion involved
  X &r = ref_to(loc);

  // local one arg constructor inside make
  // free store copy constructor inside make
  // local one arg destructor inside make
  // free strore destructor when delete is complete
  delete make(7);
  // same pattern as above line
  delete make(8);

  // 5. 4 objects default constructed
  vector<X> v(4);

  // 6. 2 X's default constructed

  XX loc4;

  // 7. one arg. constructor - free store
  X *p = new X{9};

  // 7. destructed from free store
  delete p;

  // 8. 5 X's def. constructed on free store
  X *pp = new X[5];

  // 8. 5 X's of pp destructed free store
  delete [] pp;
  // 6. 2 X's destructed from XX
  // 5. 4 objs. destructed from vector
  // 4. destructor
  // 2. destructor (from copy constructor)
  // 1. destructor
}

