
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int halveArray(vector<int> &nums) {
    double total_sum = accumulate(nums.begin(), nums.end(), 0.0);

    priority_queue<double> pq;

    // 初始化堆
    for (int p : nums)
      pq.push(p * 1.0);

    int ans = 0;
    double acc = .0;
    while (!pq.empty()) {
      double cur = pq.top();
      //      cout << "cur=" << cur << " cur/2=" << cur / 2.0
      //           << " total_sum=" << total_sum << endl;
      ans++;
      acc += cur / 2.0;
      if (acc >= total_sum / 2.0)
        break;
      pq.pop();
      pq.push(cur / 2.0);
    }

    return ans;
  }
};

int main() {
  Solution solution;
  //  vector<int> nums = {5, 19, 8, 1};
  //  vector<int> nums = {6, 58, 10, 84, 35, 8, 22, 64, 1, 78, 86, 71, 77};
  vector<int> nums = {32, 98, 23, 14, 67, 40, 26, 9,  96, 96, 91, 76,  4,
                      40, 42, 2,  31, 13, 16, 37, 62, 2,  27, 25, 100, 94,
                      14, 3,  48, 56, 64, 59, 33, 10, 74, 47, 73, 72,  89,
                      69, 15, 79, 22, 18, 53, 62, 20, 9,  76, 64};
  cout << solution.halveArray(nums) << endl;
}