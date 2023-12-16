//
// Created by sigmoidguo on 2023/12/17.
//

/**
 * 2924. 找到冠军 II
 * https://leetcode.cn/contest/weekly-contest-370/problems/find-champion-ii/
 * 1. 本质上是去求有多少个点从没有被占优过
 * 2. 遍历每个点，如果没有父节点，那么就加入冠军set
 * 3. 冠军set>1，返回-1
 * 4. 遍历边，得到一个map，key是该节点，value数组是其父节点
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int findChampion(int n, vector<vector<int>> &edges) {
    map<int, vector<int>> m;
    for (int i = 0; i < edges.size(); i++) {
      int u = edges[i][0];
      int v = edges[i][1];
      m[v].push_back(u);
    }
    set<int> s;
    for (int i = 0; i < n; i++) {
      if (m.find(i) == m.end()) {
        s.insert(i);
      }
    }
    if (s.size() > 1) {
      return -1;
    } else {
      return *s.begin();
    }
  }
};

int main() {
  //  int n = 3;
  //  vector<vector<int>> edges = {{0, 1}, {1, 2}};
  int n = 4;
  vector<vector<int>> edges = {{0, 2}, {1, 3}, {1, 2}};
  Solution solution;
  cout << solution.findChampion(n, edges) << endl;
  return 0;
}