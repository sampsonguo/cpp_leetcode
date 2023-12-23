
#include <bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.cn/leetbook/read/path-problems-in-dynamic-programming/rt1hg6/
 */
class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    int dp[m][n];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (obstacleGrid[i][j] == 1) {
          dp[i][j] = 0;
          continue;
        }
        if (i == 0 && j == 0) {
          dp[i][j] = 1;
          continue;
        }
        if (i == 0) {
          // 边界条件
          dp[i][j] = dp[i][j - 1];
          continue;
        }
        if (j == 0) {
          dp[i][j] = dp[i - 1][j];
          continue;
        }
        // 状态转移方程
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
      }
    }
    return dp[m - 1][n - 1];
  }
};

int main() {
  Solution solution;
  //  vector<vector<int>> obstacleGrid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
  vector<vector<int>> obstacleGrid = {{1}};
  cout << solution.uniquePathsWithObstacles(obstacleGrid) << endl;
}