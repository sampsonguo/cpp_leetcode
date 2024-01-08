
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int numberOfBoomerangs(vector<vector<int>> &points) {
    int ans = 0;
    for (int i = 0; i < points.size(); i++) {
      unordered_map<int, int> m;
      for (int j = 0; j < points.size(); j++) {
        if (i == j) {
          continue;
        }
        int dis =
            (points[i][0] - points[j][0]) * (points[i][0] - points[j][0]) +
            (points[i][1] - points[j][1]) * (points[i][1] - points[j][1]);
        m[dis]++;
      }
      for (auto it = m.begin(); it != m.end(); it++) {
        ans += it->second * (it->second - 1);
      }
    }
    return ans;
  }
};