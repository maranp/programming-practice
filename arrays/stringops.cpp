/*
 * stringops.cpp
 *
 *  Created on: 11-Apr-2018
 *      Author: maran
 */
#include <string>
using std::string;

#include <vector>
using std::vector;

#include <algorithm>

#include <iostream>
using std::cout;
using std::endl;

int main() {
  string s1 {"hello"};
  string s2;

  std::copy(rbegin(s1), rend(s1), std::back_inserter(s2));
  std::reverse_copy(rbegin(s1), rend(s1), std::back_inserter(s2));
  cout << s2 << endl;

  vector<int> v {1, 2, 3, 4, 5, 6};

  // auto e = v[0];
  // std::copy(std::next(begin(v)), end(v), begin(v));
  // v[v.size() - 1] = e;

  std::rotate(find(begin(v), end(v), 2), find(begin(v), end(v), 4), find(begin(v), end(v), 4) + 1);

  auto printc = [](auto const & c) {
    std::for_each(begin(c), end(c), [](auto const &e) {
      cout << e << " ";
    });
    cout << '\n';
  };
  printc(v);


  vector<int> v1 {1, 2, 3, 4, 5, 6, 7, 8};
//  std::partition(begin(v1), end(v1), [](auto e) {
//    return e % 2 != 0;
//  });

  auto partition_begin = std::stable_partition(begin(v1), end(v1), [](auto e) {
    return e % 2 != 0;
  });
  printc(v1);
  cout << *partition_begin << '\n';
  auto four = find(begin(v1), end(v1), 4);
  printc(v1);
  std::rotate(begin(v1), partition_begin, four);
  printc(v1);
}



