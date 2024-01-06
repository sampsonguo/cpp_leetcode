
#include <bits/stdc++.h>
using namespace std;

/**
 *https://leetcode.cn/problems/number-of-visible-people-in-a-queue/?envType=daily-question&envId=2024-01-05
 */
class Solution {
public:
  vector<int> canSeePersonsCount(vector<int> &heights) {
    int n = heights.size();
    vector<int> ans(n);
    stack<int> s;
    for (int i = n - 1; i >= 0; i--) {
      while (!s.empty() && heights[i] > s.top()) {
        ans[i]++;
        s.pop();
      }
      if (!s.empty()) {
        ans[i]++;
      }
      s.push(heights[i]);
    }
    return ans;
  }
};

int main() {
  Solution solution;
  //  vector<int> heights = {10, 6, 8, 5, 11, 9};
  vector<int> heights = {5, 1, 2, 3, 10};
  vector<int> ans = solution.canSeePersonsCount(heights);
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
}