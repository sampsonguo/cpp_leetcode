//
// Created by sigmoidguo on 2023/12/17.
//

#include <bits/stdc++.h>
using namespace std;

/**
 *
 */
class Solution {
public:
  vector<vector<int>> divideArray(vector<int> &nums, int k) {
    vector<vector<int>> ret, ret_empty;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i += 3) {
      vector<int> tmp;
      tmp.push_back(nums[i]);
      tmp.push_back(nums[i + 1]);
      tmp.push_back(nums[i + 2]);
      if (tmp[2] - tmp[0] <= k) {
        ret.push_back(tmp);
      } else {
        return ret_empty;
      }
    }
    return ret;
  }
};