//
// Created by sigmoidguo on 2023/12/13.
//

#include <bits/stdc++.h>
using namespace std;

/**
 * 题目:2958. 最多 K 个重复元素的最长子数组
 * 链接:https://leetcode.cn/contest/biweekly-contest-119/problems/length-of-longest-subarray-with-at-most-k-frequency/
 * 思路: 双指针, L指针和R指针向右移动, [L,R)表示满足的区间
 * 移动的次序为: 右左右左...
 */

class Solution {
public:
  int maxSubarrayLength(vector<int> &nums, int k) {
    int ret = 1;

    // 区间[L,R)
    int L = 0, R = 0;

    // 存储当前区间中的元素和出现次数
    map<int, int> m;

    // 遍历加入后面的元素
    while (L < nums.size() && R < nums.size()) {
      // 加入当前R元素，直到加不动了，即最终的R代表右侧开区间
      while (R < nums.size() &&
             // 新元素或者小于k次
             (m.find(nums[R]) == m.end() || m[nums[R]] < k)) {
        m[nums[R]]++;
        R++;
      }

      // 用[L, R)更新答案
      ret = max(ret, R - L);

      // 下一轮必须加入nums[R]，接下来移动L指针，直到满足需求(即nums[L]=nums[R])
      while (L <= R && R < nums.size() && nums[L] != nums[R]) {
        m[nums[L]]--;
        L++;
      }
      m[nums[L]]--;
      L++;
    }
    return ret;
  }
};

int main() {
  vector<int> nums = {1, 2, 3, 1, 2, 3, 1, 2};
  int k = 2;
  //  vector<int> nums = {1, 2, 1, 2, 1, 2, 1, 2};
  //  int k = 1;
  //  vector<int> nums = {5, 5, 5, 5, 5, 5, 5};
  //  int k = 4;
  Solution solution;
  cout << solution.maxSubarrayLength(nums, k) << endl;
  return 0;
}