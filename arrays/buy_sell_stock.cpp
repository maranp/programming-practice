/*
 * buy_sell_stock.cpp
 *
 *  Created on: 17-Apr-2018
 *      Author: maran
 */

#include "../ihelper.h"

void buy_sell_stock_with_max_profit() {
  vector<int> v {310, 315, 275, 295, 260, 270, 290, 230, 255, 250};
  auto min = v[0];
  auto curr_low = min;
  auto curr_high = curr_low;
 // auto min_low = min;
  auto max_range = 0;

  for (auto i = 1; i < v.size(); i++) {
    // current price - lowest price
    if (v[i] - min > max_range) {
      max_range = v[i] - min;

      curr_low = min;
      curr_high = v[i];
    }
    // track the smallest (lowest price) so far
    if (v[i] < min) {
      min = v[i];
    }
  }
  cout << max_range << " " << curr_low << " " << curr_high << '\n';
}

int main() {
  buy_sell_stock_with_max_profit();
  // modern_cpp_fibonacci();
}


void modern_cpp_fibonacci() {
  auto fibo = [i = 0, j = 1]() mutable {
    i = std::exchange(j, i + j);
    return i;
  };
  cout << fibo() << endl;
  cout << fibo() << endl;
  cout << fibo() << endl;
  cout << fibo() << endl;
  cout << fibo() << endl;
  cout << fibo() << endl;
}
