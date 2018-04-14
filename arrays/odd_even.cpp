/*
 * odd_even.cpp
 *
 *  Created on: 27-Mar-2018
 *      Author: maran
 */

#include <algorithm>
#include <vector>

#include "../ihelper.h"

int main() {
  std::vector<int> vi {23, 345, -234, 45, 89, 24};
  std::vector<int> vi2 {vi};
  std::partition(begin(vi), end(vi), [](int e) {
    // is even?
    return (e & 1) == 0;
  });
  cprint(vi);

  {
    // manual implementation
    auto even = 0;
    auto odd = vi2.size() - 1;
    while (even < odd) {
      if (vi2[even] % 2 != 0) {
        // swap if even not found and decrement odd
        std::swap(vi2[even], vi2[odd]);
        // we are not decrementing even because,
        // the swapped vi2[odd] might contain odd
        // so do not incremen even until we are sure that
        // we found even.
        odd--;
      } else {
        even++;
      }
    }
    cprint(vi2);
  }
  {
    // manual implementatio, another approach
    std::vector<int> vi3 {23, 345, -234, 45, 89, 24};
    //std::vector<int> vi3 {5, 7, 34, 56, 23, 56, 89};
    cprint(vi3);
    // find the first odd element in the array.
    // this is the place from where even elems have to be populated
    auto even = std::find_if(begin(vi3), end(vi3), [](auto e) {
      return (e & 1) != 0; // skip evens and find the first odd
    });
    // find from the last, the first which is even
    // this is where odd needs to be populated
    auto odd = std::find_if(rbegin(vi3), rend(vi3), [](auto e) {
      return (e & 1) == 0; // skip odds and find the first even
    });
    // The base iterator refers to the element that is next
    // to the element the reverse_iterator is currently pointing to.
    cout << *(odd.base() - 1) <<endl;
    while (even != odd.base() - 1) {
      if ((*even & 1) != 0) {
        std::iter_swap(even, odd);
        odd++; // odd is a reverse iterator. so, odd-- is incorrect
      } else {
        even++;
      }
    }
    cprint(vi3);
  }
}
