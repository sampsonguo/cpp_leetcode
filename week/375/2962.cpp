//
// Created by sigmoidguo on 2023/12/13.
//

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  long long countSubarrays(vector<int>& nums, int k) {

    long long ret = 0;

    // 先获取该数组中最大的值
    int max_ele = 0;
    for(int i = 0; i < nums.size(); i++) {
      max_ele = max(max_ele, nums[i]);
    }
    // cout << "... " << max_ele << endl;

    // 开始点、结束点
    int lp = -1;
    int rp = 0; // right_pointer
    int cnt = 0;
    while(cnt < k && rp < nums.size()) {
      if(nums[rp] == max_ele) {
        if(lp == -1) {
          lp = rp;
        }
        cnt++;
        if(cnt == k) break;
      }
      rp++;
    }
    // cout << "... " << lp << " " << rp << " " << cnt << endl;

    // 如果找不到
    if(cnt != k) {
      return 0;
    }
    ret += lp+1;
    rp++;

    // 其他是可以找到的情况
    // rp逐渐向右侧移动
    while(rp < nums.size()) {
      // cout << "... " << lp << " " << rp << " " << cnt << endl;
      // 找到了下一个rp应该在的点
      if(nums[rp] == max_ele) {
        // 再移动lp
        while(nums[lp+1] != max_ele) lp++;
        lp++;
      }
      ret += lp+1;
      rp++;
    }
    return ret;
  }
};

int main() {
  vector<int> nums = {1,3,2,3,3};
  int k = 3;
  Solution solution;
  cout << solution.countSubarrays(nums, k) << endl;
  return 0;
}