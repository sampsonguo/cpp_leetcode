//
// Created by sigmoidguo on 2023/12/19.
//

#include <bits/stdc++.h>
using namespace std;

/**
 * 2917. 找出数组中的 K-or 值
 * https://leetcode.cn/contest/weekly-contest-369/problems/find-the-k-or-of-an-array/
 */

class Solution {
public:
  int findKOr(vector<int> &nums, int k) {
    int ret = 0;
    for (int i = 0; i < 32; i++) {
      int cnt = 0;
      for (int x : nums) {
        if (x & (1 << i)) {
          cnt++;
        }
        if (cnt >= k) {
          ret |= (1 << i);
        }
      }
    }
    return ret;
  }
};

int main() {
  //  vector<int> nums = {7, 12, 9, 8, 9, 15};
  //  int k = 4;
  //  vector<int> nums = {2, 12, 1, 11, 4, 5};
  //  int k = 6;
  vector<int> nums = {10, 8, 5, 9, 11, 6, 8};
  int k = 1;
  Solution solution;
  cout << solution.findKOr(nums, k) << endl;
  return 0;
}