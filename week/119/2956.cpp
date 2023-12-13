//
// Created by sigmoidguo on 2023/12/13.
//

#include <bits/stdc++.h>
using namespace std;

// 2956. 找到两个数组中的公共元素
// https://leetcode.cn/contest/biweekly-contest-119/problems/find-common-elements-between-two-arrays/

class Solution {
public:
  vector<int> findIntersectionValues(vector<int> &nums1, vector<int> &nums2) {
    vector<int> ret;

    // 构造set1、set2
    unordered_set<int> s1, s2;
    for (int x : nums1) {
      s1.insert(x);
    }
    for (int x : nums2) {
      s2.insert(x);
    }

    // 查询和计数
    int cnt1 = 0, cnt2 = 0;
    for (int x : nums1) {
      if (s2.find(x) != s2.end()) {
        cnt1++;
      }
    }
    for (int x : nums2) {
      if (s1.find(x) != s1.end()) {
        cnt2++;
      }
    }

    // 加入集合
    ret.push_back(cnt1);
    ret.push_back(cnt2);

    return ret;
  }
};

int main() {
  //  vector<int> nums1 = {4, 3, 2, 3, 1};
  //  vector<int> nums2 = {2, 2, 5, 2, 3, 6};
  vector<int> nums1 = {3, 4, 2, 3};
  vector<int> nums2 = {1, 5};
  Solution solution;
  vector<int> ret = solution.findIntersectionValues(nums1, nums2);
  for (int i = 0; i < ret.size(); i++) {
    cout << ret[i] << " ";
  }
  cout << endl;
  return 0;
}