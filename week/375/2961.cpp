//
// Created by sigmoidguo on 2023/12/13.
//

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
    vector<int> ret;
    for(int i = 0; i < variables.size(); i++) {
      int ans = 1;
      int a = variables[i][0];
      int b = variables[i][1];
      int c = variables[i][2];
      int m = variables[i][3];
      // printf("%d %d %d %d\n", a, b, c, m);
      for(int j = 0; j < b; j++) {
        ans *= a;
        ans %= 10;
      }
      // printf(".. %d\n", ans);
      int d = ans;
      ans = 1;
      for(int j = 0; j < c; j++) {
        ans *= d;
        ans %= m;
      }
      // printf(".. %d\n", ans);
      if(ans == target) {
        ret.push_back(i);
      }
    }
    return ret;
  }
};

int main() {
  vector<vector<int>> variables = {{2,2,2,2},{2,2,3,3},{2,3,2,3},{2,3,3,2},{3,2,2,3},{3,2,3,2},{3,3,2,2},{3,3,3,3}};
  int target = 2;
  Solution solution;
  vector<int> ret = solution.getGoodIndices(variables, target);
  for(int i = 0; i < ret.size(); i++) {
    cout << ret[i] << " ";
  }
  cout << endl;
  return 0;
}