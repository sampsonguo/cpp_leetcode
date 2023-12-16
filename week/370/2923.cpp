//
// Created by sigmoidguo on 2023/12/17.
//

/**
 * 2923. 找到冠军
 *https://leetcode.cn/contest/weekly-contest-370/problems/find-champion-i/
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int findChampion(vector<vector<int>> &grid) {
    for (int i = 0; i < grid.size(); i++) {
      bool flag = true;
      for (int j = 0; j < grid[i].size(); j++) {
        if (i != j && grid[i][j] == 0) { // 不满足
          flag = false;
        }
      }
      if (flag) {
        return i;
      }
    }
    return 0;
  }
};

int main() {
  vector<vector<int>> grid = {{0, 1}, {0, 0}};
  //  vector<vector<int>> grid = {{0, 0, 1}, {1, 0, 1}, {0, 0, 0}};
  Solution solution;
  cout << solution.findChampion(grid) << endl;
  return 0;
}