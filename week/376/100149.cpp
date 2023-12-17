//
// Created by sigmoidguo on 2023/12/17.
//

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid) {
    int sum = 0;
    set<int> s;
    vector<int> ret;
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[i].size(); j++) {
        sum += grid[i][j];
        if (s.find(grid[i][j]) != s.end()) {
          ret.push_back(grid[i][j]);
        }
        s.insert(grid[i][j]);
      }
    }
    int n = grid.size();
    ret.push_back((1 + n * n) * (n * n) / 2 + ret[0] - sum);
    return ret;
  }
};