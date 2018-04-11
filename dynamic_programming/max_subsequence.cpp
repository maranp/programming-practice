/*
 * max_subsequence.cpp
 *
 *  Created on: 11-Apr-2018
 *      Author: maran
 */

#include "ihelper.h"

template <typename T>
auto max_subsequence_1(vector<T> const & v) {
  T max_sum = 0;
  T min_sum = 0;
  T sum = 0;
  for (auto e : v) {
    sum += e;
    if (sum < min_sum) {
      // running sum pulls down the gross value
      // track it
      min_sum = sum;
    }
    // sum - min_sum gives the effective value of partial total accounted so far
    // update max_sum if this partial_total exceeds max_sum
    if ((sum - min_sum) > max_sum) {
      max_sum = sum - min_sum;
    }
  }
  return max_sum;
}

template <typename T>
auto max_subsequence(vector<T> const & v) {
  T max_sum = 0;

  for_each(begin(v), end(v), [&max_sum, min_sum = 0, sum = 0](auto const &e) mutable {
    sum += e;
    if (sum < min_sum) {
      min_sum = sum;
    }
    if ((sum - min_sum) > max_sum) {
      max_sum = sum - min_sum;
    }
  });
  return max_sum;
}

int main() {
  // vector<int> v {-1, 5, 4, -1, 2, 7, -10};
  // assuming we know max subarray count of a[0 - (n-2)]
  // when finding the combined result including a[n - 1],
  // either the max amt of the subarray that doesn't extend till n - 2 win
  // or the max subarray at end combined with a[n - 1] win
  // here a[0], a[1] win if a[n - 1] < 4
  // or a[n - 2], a[n - 1] win if a[n - 1] > 5
  vector<int> v {-1, 5, 4, -5, -5, 5, 5};
  cprint(v);

  auto max_sum = v[0];
  for (auto i = 0; i < v.size(); i++) {
    auto sum = 0;
    for (auto j = i; j < v.size(); j++) {
      sum += v[j];
      if (sum > max_sum) {
        cout << i << " " << j << endl;
        max_sum = sum;
      }
    }
  }
  cout << max_sum << '\n';

  cout << max_subsequence(v) << '\n';
  return 0;
}



