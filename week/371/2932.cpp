//
// Created by sigmoidguo on 2023/12/16.
//

#include <bits/stdc++.h>
using namespace std;

/**
 *2932. 找出强数对的最大异或值 I
 *https://leetcode.cn/contest/weekly-contest-371/problems/maximum-strong-pair-xor-i/
 */
class Solution {
public:
  int maximumStrongPairXor(vector<int> &nums) {
    int ret = 0;
    for (int i = 0; i < nums.size(); i++) {
      for (int j = i + 1; j < nums.size(); j++) {
        int x = nums[i];
        int y = nums[j];
        if (abs(x - y) <= min(x, y)) {
          ret = max(ret, x ^ y);
        }
      }
    }
    return ret;
  }
};

int main() {
  //  vector<int> nums = {1, 2, 3, 4, 5};
  //  vector<int> nums = {10, 100};
  vector<int> nums = {5, 6, 25, 30};
  Solution solution;
  cout << solution.maximumStrongPairXor(nums) << endl;
  return 0;
}