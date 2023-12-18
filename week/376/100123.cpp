//
// Created by sigmoidguo on 2023/12/17.
//

#include <bits/stdc++.h>
using namespace std;

/**
 * 100123. 执行操作使频率分数最大
 *https://leetcode.cn/problems/apply-operations-to-maximize-frequency-score/
 * 1、目标数字是中位数,因为中位数的左右两边的数字个数是相同的，所以是最优化的最低点
 * 2、维护一个[L,R]的区间
 * 3、通过预处理的方法，使得能快速计算[L,R]是否满足条件，即需要的数字是否>k
 */
class Solution {
public:
  long long f(int i, int j, vector<int> &nums, vector<long long> &pre) {
    int mid = (i + j) / 2;
    long long ans = (pre[j] - pre[mid]) - (nums[mid] * 1LL * (j - mid)) +
                    (nums[mid] - nums[i]) * (mid - i + 1LL) -
                    ((pre[mid] - pre[i]) - (nums[i] * (mid - i * 1LL)));
    return ans;
  }

  int maxFrequencyScore(vector<int> &nums, long long k) {
    int n = nums.size();
    sort(nums.begin(), nums.end());

    // 预处理 [1,n] 从1到n
    vector<long long> pre(n);
    pre[0] = nums[0];
    for (int i = 1; i < n; i++) {
      pre[i] = pre[i - 1] + nums[i];
    }

    int ans = 0;
    for (int i = 0, j = 0; i < n; i++) {
      while (j <= i && f(j, i, nums, pre) > k) {
        j++;
      }
      ans = max(ans, i - j + 1);
    }
    return ans;
  }
};

int main() {
  //  vector<int> nums = {1, 2, 6, 4};
  //  long long k = 3;
  //  vector<int> nums = {1, 4, 4, 2, 4};
  //  long long k = 0;
  vector<int> nums = {3, 20, 13, 2, 3, 15, 24, 19, 8, 13, 19, 20, 21};
  long long k = 45;
  Solution solution;
  cout << solution.maxFrequencyScore(nums, k) << endl;
  return 0;
}