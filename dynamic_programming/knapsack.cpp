/*
 * knapsack.cpp
 *
 *  Created on: 12-Apr-2018
 *      Author: maran
 */

#include "ihelper.h"

void find_config(vector<int> const &weight, int total, vector<int> &config, int idx) {
  auto weight_factor = total / weight[idx];
  auto balance = total - (weight_factor * weight[idx]);

  // this weight_factor may not be the actual config
  // if not found to be the right factor, reset it to zero before wrapping up
  config[idx] = weight_factor;
  if (balance == 0) {
    // found a candidate print it
    cprint(config);
    // since balance is 0, the configuration is final
    // with this weight factor. we dont want it tobe processed again
    // when invoking find_config for next level
    weight_factor--;
  }
  if (idx == (weight.size() - 1)) {
    // explored all the weight factors for this configuration. going back to explore another configuration
    // before that, reset the weight factor
    config[idx] = 0;
    return;
  } else {
    // we have to explore the next level weight (idx + 1)
    // for each possible weight factor of this level (weight_factor .. 0)
    while (weight_factor >= 0) {
      config[idx] = weight_factor;

      balance = total - (weight_factor * weight[idx]);
      find_config(weight, balance, config, idx + 1);
      weight_factor--;
    }
  }
  // paranoia reset to zero
  config[idx] = 0;
  return;
}

int main() {
  vector<int> w {7, 3, 2};
  auto total = 12;
  vector<int> config {0, 0, 0};

  find_config(w, total, config, 0);
}
