//
// Created by sigmoidguo on 2023/12/16.
//

/**
 * 2934. 最大化数组
 *  https://leetcode.cn/problems/minimum-operations-to-maximize-last-elements-in-arrays/
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minOperations(vector<int> &nums1, vector<int> &nums2) {
    // 判断是否返回-1
    int n = nums1.size();
    int min_max = 0;
    int max_max = 0;
    for (int i = 0; i < n; i++) {
      min_max = max(min_max, min(nums1[i], nums2[i]));
      max_max = max(max_max, max(nums1[i], nums2[i]));
    }
    if (!(min(nums1[n - 1], nums2[n - 1]) == min_max &&
          max(nums1[n - 1], nums2[n - 1]) == max_max)) {
      return -1;
    }

    // 最后一位不换位
    int opt1 = 0;
    for (int i = 0; i < n; i++) {
      if (nums1[i] <= nums1[n - 1] && nums2[i] <= nums2[n - 1]) {
        continue;
      } else {
        opt1++;
      }
    }

    // 最后一位换位
    int opt2 = 1;
    swap(nums1[n - 1], nums2[n - 1]);
    for (int i = 0; i < n; i++) {
      if (nums1[i] <= nums1[n - 1] && nums2[i] <= nums2[n - 1]) {
        continue;
      } else {
        opt2++;
      }
    }
    return min(opt1, opt2);
  }
};

int main() {
  //  vector<int> nums1 = {1, 2, 7};
  //  vector<int> nums2 = {4, 5, 3};
  //  vector<int> nums1 = {2, 3, 4, 5, 9};
  //  vector<int> nums2 = {8, 8, 4, 4, 4};
  vector<int> nums1 = {1, 5, 4};
  vector<int> nums2 = {2, 5, 3};
  Solution solution;
  cout << solution.minOperations(nums1, nums2) << endl;
  return 0;
}