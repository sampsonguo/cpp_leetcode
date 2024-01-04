
#include <bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.cn/problems/maximum-rows-covered-by-columns/?envType=daily-question&envId=2024-01-04
 */
class Solution {
public:
  static int count_binary(int x) {
    int cnt = 0;
    while (x) {
      cnt += x & 1;
      x >>= 1;
    }
    return cnt;
  }
  int maximumRows(vector<vector<int>> &matrix, int numSelect) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> v;
    // 二进制
    // 000
    // 101
    // 011
    // 001
    for (int i = 0; i < m; i++) {
      int now = 0;
      for (int j = 0; j < n; j++) {
        now <<= 1;
        now += matrix[i][j];
      }
      v.push_back(now);
    }
    int ans = 0;
    for (int cover = 0; cover <= (1 << n) - 1; cover++) {
      if (count_binary(cover) != numSelect) {
        continue;
      }
      int cnt = 0;
      for (int i = 0; i < m; i++) {
        //        cout << v[i] << " " << cover << endl;
        if ((v[i] & cover) == v[i]) {
          //          cout << ".. " << cover << endl;
          cnt++;
        }
      }
      ans = max(ans, cnt);
    }
    return ans;
  }
};

int main() {
  Solution solution;
  vector<vector<int>> matrix = {{0, 0, 0}, {1, 0, 1}, {0, 1, 1}, {0, 0, 1}};
  //  vector<vector<int>> matrix = {{0, 1}, {1, 0}};
  int numSelect = 2;
  cout << solution.maximumRows(matrix, numSelect) << endl;
};