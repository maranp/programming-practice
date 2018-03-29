/*
 * fibonacci.cpp
 *
 *  Created on: 15-Mar-2018
 *      Author: maran
 */
#include <fibonacci.h>
#include <unordered_map>

long fibonacci(long n) {
  if (n < 2)
    return n;
  return fibonacci(n - 1) + fibonacci(n - 2);
}

long fib_cache(long n) {
  static std::unordered_map<long, long> cache;

  if (n < 2)
    return n;

  if (cache.count(n))
    return cache[n];

  return cache[n] = fib_cache(n - 1) + fib_cache(n - 2);
}

long fib_o_n(long n) {
  if (n < 2)
    return n;

  auto p = 0;
  auto q = 1;
  long res;
  for (auto i = 2; i <= n; i++) {
    res = p + q;
    p = q;
    q = res;
  }
  return res;
}
