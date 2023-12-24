
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  long long minimumCost(string source, string target, vector<char> &original,
                        vector<char> &changed, vector<int> &cost) {
    // 初始化两点距离, 有向图
    int dist[26][26];
    memset(dist, -1, sizeof(dist));
    for (int i = 0; i < original.size(); i++) {
      if (dist[original[i] - 'a'][changed[i] - 'a'] == -1) {
        dist[original[i] - 'a'][changed[i] - 'a'] = cost[i];
      } else {
        dist[original[i] - 'a'][changed[i] - 'a'] =
            min(dist[original[i] - 'a'][changed[i] - 'a'], cost[i]);
      }
    }

    // 初始化自己到自己的距离
    for (int i = 0; i < 26; i++) {
      dist[i][i] = 0;
    }

    // floyd算法
    for (int k = 0; k < 26; k++) {
      for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
          if (dist[i][k] != -1 && dist[k][j] != -1) {
            if (dist[i][j] == -1) {
              dist[i][j] = dist[i][k] + dist[k][j];
            } else {
              dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
          }
        }
      }
    }

    //    for (int i = 0; i < 26; i++) {
    //      for (int j = 0; j < 26; j++) {
    //        cout << dist[i][j] << " ";
    //      }
    //      cout << endl;
    //    }

    // 计算最小代价
    long long ans = 0;
    for (int i = 0; i < source.size(); i++) {
      if (source[i] == target[i])
        continue;
      if (dist[source[i] - 'a'][target[i] - 'a'] == -1) {
        //        cout << source[i] << " " << target[i] << endl;
        return -1;
      } else {
        ans += dist[source[i] - 'a'][target[i] - 'a'];
      }
    }
    return ans;
  }
};

int main() {
  Solution solution;
  string source = "abcd";
  string target = "acbe";
  vector<char> original = {'a', 'b', 'c', 'c', 'e', 'd'};
  vector<char> changed = {'b', 'c', 'b', 'e', 'b', 'e'};
  vector<int> cost = {2, 5, 5, 1, 2, 20};
  cout << solution.minimumCost(source, target, original, changed, cost) << endl;
}