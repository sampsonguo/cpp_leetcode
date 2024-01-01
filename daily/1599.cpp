
#include <bits/stdc++.h>
using namespace std;

/**
 *https://leetcode.cn/problems/maximum-profit-of-operating-a-centennial-wheel/?envType=daily-question&envId=2024-01-01
 */
class Solution {
public:
  int minOperationsMaxProfit(vector<int> &customers, int boardingCost,
                             int runningCost) {
    int ans = -1;
    int n = customers.size();
    int cur = 0;
    int max_profit = 0;
    int profit = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      cur += customers[i];
      if (cur >= 4) {
        cnt += 4;
        cur -= 4;
      } else {
        cnt += cur;
        cur = 0;
      }
      profit = cnt * boardingCost - (i + 1) * runningCost;
      if (profit > max_profit) {
        max_profit = profit;
        ans = i + 1;
      }
    }
    while (cur > 0) {
      if (cur >= 4) {
        cnt += 4;
        cur -= 4;
      } else {
        cnt += cur;
        cur = 0;
      }
      profit = cnt * boardingCost - (n + 1) * runningCost;
      if (profit > max_profit) {
        max_profit = profit;
        ans = n + 1;
      }
      n++;
    }
    return ans;
  }
};

int main() {
  Solution solution;
  vector<int> customers = {8, 3};
  int boardingCost = 5;
  int runningCost = 6;
  cout << solution.minOperationsMaxProfit(customers, boardingCost, runningCost)
       << endl;
}