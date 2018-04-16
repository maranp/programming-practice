/*
 * advanc ing_an_array.cpp
 *
 *  Created on: 15-Apr-2018
 *      Author: maran
 */

#include "../ihelper.h"

#include <ostream>
#include <iterator>
void advance_an_array() {
  // test cases
  std::vector<int> v {2, 1, 2, 4, 2, 1, 3, 2, 0};
//  std::vector<int> v {3, 3, 1, 0, 2, 0, 1};
//  std::vector<int> v {3, 2, 0, 0, 2, 0, 1};
  std::vector<int> tracker (v.size(), 0);
  auto reached_so_far = 0;

  // we begin to hop from v[0] and we can reach until v[0]'s value
  reached_so_far += v[0];
  // i = 1 => we explore from v[1] whether it can help extending the reach
  // i <= reached_so_far => we cannot examine how far v[i] can take us,
  // because, (i > reached_so_far) means, the hopping so far did not take us until i
  for (auto i = 1; i < v.size() && i <= reached_so_far; i++) {
    auto last_reached_so_far = reached_so_far;
    // reached_so_far is the new extent to which v[i] can take us
    reached_so_far = (i + v[i] > reached_so_far) ? i + v[i] : last_reached_so_far;

    if (reached_so_far >= v.size() - 1) {
      tracker.back() = i;
      break;
    }
    // last_reached_so_far - reached_so_far is the range to which v[i] takes us to.
    // so, set this range in the tracker with i
    for (auto j = last_reached_so_far + 1; j <= reached_so_far; j++) {
      tracker[j] = i;
    }
  }
  cprint(tracker);
  // if the hopping did not take us until end of the array,
  // the last element of tracker would not have the last index of the array
  if (tracker.back() == 0) {
    std::cout << "array cant be advanced until its end\n";
    return;
  }
  std::vector<int> res(tracker.size());
  auto count = 0;
  res[count++] = v.size() - 1;
  for (auto i = tracker.size() - 1; i > 0;) {
    res[count++] = tracker[i];
    i = tracker[i];
  }
  //std::copy(std::reverse_iterator(begin(res) + count), std::reverse_iterator(begin(res)), std::ostream_iterator<int>(std::cout, ", "));
  iprint(std::reverse_iterator(begin(res) + count), std::reverse_iterator(begin(res)));
}

int main() {
  advance_an_array();
}
