//
// Created by sigmoidguo on 2023/12/17.
//

/**
 * 2925. 树上应用操作后的最大得分
 * https://leetcode.cn/contest/weekly-contest-370/problems/maximum-score-after-applying-operations-on-a-tree/
 * 一句话，保留子节点还是根节点，通过取值比较
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  long long dfs(int root, bool visited[], vector<vector<int>> &adjs,
                vector<int> &values) {
    // 该节点已经访问过了
    visited[root] = true;

    // 该节点的子节点
    long long children_sum = 0;
    vector<int> children = adjs[root];
    for (int i = 0; i < children.size(); i++) {
      if (visited[children[i]]) {
        continue;
      }
      children_sum += dfs(children[i], visited, adjs, values);
    }

    // 如果是叶子节点，返回值
    if (children_sum == 0) {
      return values[root];
    }

    // 返回两种方案种的较优值
    return min(children_sum, (long long)values[root]);
  }

  long long maximumScoreAfterOperations(vector<vector<int>> &edges,
                                        vector<int> &values) {
    // 当前的全部权重
    int n = values.size();
    long long total_sum = 0;
    for (int i = 0; i < n; i++) {
      total_sum += values[i];
    }

    // 构造邻接表
    vector<vector<int>> adj(n);
    for (int i = 0; i < edges.size(); i++) {
      adj[edges[i][0]].push_back(edges[i][1]);
      adj[edges[i][1]].push_back(edges[i][0]);
    }

    // 优化后的总权重
    bool visited[n];
    memset(visited, false, sizeof(visited));
    long long opt_sum = dfs(0, visited, adj, values);

    return total_sum - opt_sum;
  }
};

int main() {
  //  vector<vector<int>> edges = {{0, 1}, {1, 2}, {0, 3}};
  //  vector<int> values = {1, 2, 3, 4};
  vector<vector<int>> edges = {{0, 1}, {0, 2}, {0, 3}, {2, 4}, {4, 5}};
  vector<int> values = {5, 2, 5, 2, 1, 1};
  Solution solution;
  cout << solution.maximumScoreAfterOperations(edges, values) << endl;
  return 0;
}