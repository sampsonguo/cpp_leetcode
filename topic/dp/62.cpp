
#include <bits/stdc++.h>
using namespace std;

/**
 *https://leetcode.cn/leetbook/read/path-problems-in-dynamic-programming/rtwu06/
 */
class Solution {
public:
  int uniquePaths(int m, int n) {
    int dp[m][n];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (i == 0 || j == 0) {
          // 边界条件
          dp[i][j] = 1;
        } else {
          // 状态转移方程
          dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
      }
    }
    return dp[m - 1][n - 1];
  }
};

int main() {
  Solution solution;
  //  cout << solution.uniquePaths(3, 7) << endl;
  //  cout << solution.uniquePaths(3, 2) << endl;
  //  cout << solution.uniquePaths(7, 3) << endl;
  cout << solution.uniquePaths(3, 3) << endl;
}