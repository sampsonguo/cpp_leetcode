//
// Created by sigmoidguo on 2023/12/19.
//

#include <bits/stdc++.h>
using namespace std;

/**
 * 2918. 数组的最小相等和
 * https://leetcode.cn/contest/weekly-contest-369/problems/minimum-equal-sum-of-two-arrays-after-replacing-zeros/
 */
class Solution {
public:
  long long minSum(vector<int> &nums1, vector<int> &nums2) {
    bool flag_1 = false, flag_2 = false;
    for (int i = 0; i < nums1.size(); i++) {
      if (nums1[i] == 0) {
        nums1[i] = 1;
        flag_1 = true;
      }
    }
    for (int i = 0; i < nums2.size(); i++) {
      if (nums2[i] == 0) {
        nums2[i] = 1;
        flag_2 = true;
      }
    }

    long long sum1 = accumulate(nums1.begin(), nums1.end(), 0L);
    long long sum2 = accumulate(nums2.begin(), nums2.end(), 0L);

    if (sum1 > sum2 && !flag_2) {
      return -1;
    }

    if (sum2 > sum1 && !flag_1) {
      return -1;
    }

    return max(sum1, sum2);
  }
};

int main() {
  vector<int> nums1 = {2, 0, 2, 0};
  vector<int> nums2 = {1, 4};
  //  vector<int> nums1 = {3, 2, 0, 1, 0};
  //  vector<int> nums2 = {6, 5, 0};
  Solution solution;
  cout << solution.minSum(nums1, nums2) << endl;
  return 0;
}