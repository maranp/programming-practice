/*
 * replace_remove.cpp
 *
 *  Created on: 28-Mar-2018
 *      Author: maran
 */

#include <string>
#include <algorithm>
#include <iostream>

void replace_remove_algo() {
  std::string in {"acdbbca"};
  //std::string in {"abac"};
  // remove b's
  in.erase(std::remove(begin(in), end(in), 'b'), end(in));
  std::cout << in << '\n';
  // replace a by "dd"
  std::cout
  << std::accumulate(begin(in), end(in), std::string{""}, [](std::string accum, char c) {
    if (c == 'a') {
      return accum + "dd";
    } else {
      return accum + c;
    }
  })
  << '\n';

}

void replace_remove_manual() {
  //std::string in {"acdbbca"};
  std::string in {"abac "};
  auto final_length = std::accumulate(begin(in), end(in), std::size_t {0},  [](std::size_t accum, char c) {
    if (c == 'a') {
      return accum + 2;
    } else if (c == 'b') {
      return accum;
    } else {
      return accum + 1;
    }
  });
  std::cout << final_length << '\n';
  std::cout << in.size() << '\n';

  auto i = in.size() - 1;
  auto j = final_length - 1;
  while (i >= 0) {
    if (in[i] == 'a') {
      in[j--] = 'd';
      in[j--] = 'd';
    } else if (in[i] == 'b') {

    } else {
      in[j--] = in[i];
    }
    i--;
  }
  std::cout << in << '\n';
}

int main() {
  replace_remove_algo();
  replace_remove_manual();

}



