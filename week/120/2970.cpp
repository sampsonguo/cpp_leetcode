
#include <bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.cn/problems/count-the-number-of-incremovable-subarrays-i/description/
 */
class Solution {
public:
  int incremovableSubarrayCount(vector<int> &nums) {
    int ans = 0;
    int n = nums.size();
    for (int st = 0; st < n; st++) {
      for (int ed = st; ed < n; ed++) {
        bool flag = true;
        vector<int> v = nums;
        v.erase(v.begin() + st, v.begin() + ed + 1);
        int m = v.size();
        for (int i = 0; i < m - 1; i++) {
          if (v[i] >= v[i + 1]) {
            flag = false;
            break;
          }
        }
        if (flag) {
          ans++;
        }
      }
    }
    return ans;
  }
};

int main() {
  Solution solution;
  vector<int> nums = {1, 2};
  cout << solution.incremovableSubarrayCount(nums) << endl;
}