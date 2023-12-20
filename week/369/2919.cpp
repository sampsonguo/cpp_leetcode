//
// Created by sigmoidguo on 2023/12/19.
//

/**
 * 2919. 使数组变美的最小增量运算符
 *https://leetcode.cn/problems/minimum-increment-operations-to-make-array-beautiful/
 * 1. 假设数组[1,n]已经满足美丽数组，考虑第n+1的情况，有三种情况:
 *  * 情况1:
 *第n-2个数是一个美丽数，第n-1和第n个数字不是美丽数，导致第n+1个数必须为美丽数
 *  * 情况2: 第n-1个数或者第n是一个美丽数，导致第n+1个数可以不是美丽数
 * 2. 因此，用dp[n][2]来表示倒数2个数大概率为非美丽数（或者允许为非美丽数)
 *倒数第3个数字为美丽数,即右侧有两个非美丽数
 * 3.
 *dp[n][1]表示倒数1个数字为非美丽数，倒数第2个数字为美丽数，即右侧有一个非美丽数
 * 4. dp[n][0]表示最后一个数字是美丽数，即右侧非美丽数的个数为0
 * 5. 状态转移方程为:
 * dp[n][0] = max(dp[n-1][0], dp[n-1][1], dp[n-1][2]) + max(k - nums[n], 0)
 * dp[n][1] = dp[n-1][0]
 * dp[n][2] = dp[n-1][1]
 * if(nums[n] < k) {
 * dp[n][2] = dp[n-1][1]
 * dp[n][1] = dp[n-1][0]
 * dp[n][0] = max(dp[n-1][0], dp[n-1][1], dp[n-1][2]) + max(k - nums[n], 0)
 * }
 * if(nus[n] > k} {
 * dp[n][0] = max(dp[n-1][0], dp[n-1][1], dp[n-1][2]);
 * dp[n][1] = -1;
 * dp[n][2] = -1; --路径不存在
 * }
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  static long long f(map<pair<int, int>, long long> &dp, vector<int> &nums,
                     int k, int n, int m) {
    // 如果找到，直接返回
    if (dp.find(make_pair(n, m)) != dp.end()) {
      return dp[make_pair(n, m)];
    }

    if (n == 1) {
      dp[make_pair(n, 0)] = max(k - nums[n - 1], 0);
      dp[make_pair(n, 1)] = 0;
      dp[make_pair(n, 2)] = 0;
      return dp[make_pair(n, m)];
    }

    dp[make_pair(n, 0)] =
        min(f(dp, nums, k, n - 1, 2),
            min(f(dp, nums, k, n - 1, 0), f(dp, nums, k, n - 1, 1))) +
        max(k - nums[n - 1], 0);
    dp[make_pair(n, 1)] = f(dp, nums, k, n - 1, 0);
    dp[make_pair(n, 2)] = f(dp, nums, k, n - 1, 1);
    return dp[make_pair(n, m)];
  }
  long long minIncrementOperations(vector<int> &nums, int k) {
    map<pair<int, int>, long long> dp;
    return min(
        f(dp, nums, k, nums.size(), 0),
        min(f(dp, nums, k, nums.size(), 1), f(dp, nums, k, nums.size(), 2)));
  }
};

int main() {
  //  vector<int> nums = {1, 1, 2};
  //  int k = 1;
  //  vector<int> nums = {0, 1, 3, 3};
  //  int k = 5;
  vector<int> nums = {2, 3, 0, 0, 2};
  int k = 4;
  //  vector<int> nums = {4, 0, 10, 2, 10, 6};
  //  int k = 8;
  //  vector<int> nums = {13, 34, 0, 13, 9, 19};
  //  int k = 82;
  Solution solution;
  cout << solution.minIncrementOperations(nums, k) << endl;
  return 0;
}