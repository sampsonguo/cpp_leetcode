#include <bits/stdc++.h>
using namespace std;

/**
 *https://leetcode.cn/problems/take-gifts-from-the-richest-pile/
 */
class Solution {
public:
  long long maxKelements(vector<int> &nums, int k) {
    priority_queue<int> pq;

    // 初始化堆
    for (int p : nums)
      pq.push(p);

    long long ans = 0;
    while (k--) {
      int cur = pq.top();
      ans += cur;
      pq.pop();
      pq.push(ceil(cur / 3.0));
      //      cout << "cur=" << cur << " ceil(cur/3)=" << ceil(cur / 3) << endl;
    }

    return ans;
  }
};

int main() {
  Solution solution;
  vector<int> nums = {1, 10, 3, 3, 3};
  cout << solution.maxKelements(nums, 3) << endl;
}