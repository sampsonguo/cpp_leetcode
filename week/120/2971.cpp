
#include <bits/stdc++.h>
using namespace std;

/**
 *https://leetcode.cn/problems/find-polygon-with-the-largest-perimeter/
 */
class Solution {
public:
  long long largestPerimeter(vector<int> &nums) {
    int n = nums.size();
    if (n < 3) {
      return -1;
    }

    // 首先由小到大排序
    sort(nums.begin(), nums.end());

    // 预处理求和
    vector<long long> pre_sum(n, 0);
    pre_sum[0] = nums[0];
    for (int i = 1; i < n; i++) {
      pre_sum[i] = pre_sum[i - 1] + nums[i];
    }
    long long ans = -1;
    for (int i = 2; i < n; i++) {
      if (pre_sum[i] > 2 * nums[i]) {
        ans = max(ans, pre_sum[i]);
      }
    }
    return ans;
  }
};

int main() {
  Solution solution;
  //  vector<int> nums = {5, 5, 5};
  //  vector<int> nums = {1, 12, 1, 2, 5, 50, 3};
  vector<int> nums = {5, 5, 50};
  cout << solution.largestPerimeter(nums) << endl;
}