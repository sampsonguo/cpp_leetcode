//
// Created by sigmoidguo on 2023/12/14.
//

#include <bits/stdc++.h>
using namespace std;

/**
 * 2944. 购买水果需要的最少金币数
 * https://leetcode.cn/contest/biweekly-contest-118/problems/minimum-number-of-coins-for-fruits/
 */

class Solution {
public:
  int dp[1005];
  int new_minimumCoins(vector<int> &prices, int n) {
    // 记忆化
    if (dp[n] != -1)
      return dp[n];

    // 边界值
    if (n <= 0) {
      dp[n] = 0;
      return 0;
    }

    int x = (n + 1) / 2;
    int ret = INT_MAX;
    for (int i = max(x - 1, 0); i < n; i++) {
      ret = min(ret, prices[i] + new_minimumCoins(prices, i));
    }

    dp[n] = ret;
    return ret;
  }

  int minimumCoins(vector<int> &prices) {
    memset(dp, -1, sizeof(dp));
    return new_minimumCoins(prices, prices.size());
  }
};

int main() {
  //  vector<int> prices = {3};
  //  vector<int> prices = {3, 1, 2};
  //  vector<int> prices = {1, 10, 1, 1};
  vector<int> prices = {38, 23, 27, 32, 47, 45, 48, 24, 39, 26,
                        37, 42, 24, 45, 27, 26, 15, 16, 26, 6};
  Solution solution;
  cout << solution.minimumCoins(prices) << endl;
  return 0;
}