//
// Created by sigmoidguo on 2023/12/14.
//

#include <bits/stdc++.h>
using namespace std;

/**
 * 2943. 最大化网格图中正方形空洞的面积
 *https://leetcode.cn/contest/biweekly-contest-118/problems/maximize-area-of-square-hole-in-grid/
 * 1、求出横轴和纵轴的线段集合
 *   1.1、hbars种最长的连续值为l
 *   1.2 集合为[1,l+1]
 * 2、集合求交接取最大值x
 *  2.1 等价于取两个l的较小值
 * 3、x*x为结果
 */
class Solution {
public:
  static int max_continue_length(vector<int> &v) {
    int ret = 1;
    int now = 1;
    for (int i = 1; i < v.size(); i++) {
      if (v[i] == v[i - 1] + 1) {
        now++;
      } else {
        now = 1;
      }
      ret = max(ret, now);
    }
    return ret;
  }
  int maximizeSquareHoleArea(int n, int m, vector<int> &hBars,
                             vector<int> &vBars) {
    sort(hBars.begin(), hBars.end());
    sort(vBars.begin(), vBars.end());
    int h_max = max_continue_length(hBars);
    int v_max = max_continue_length(vBars);
    int ret = min(h_max, v_max) + 1;
    return ret * ret;
  }
};

int main() {
  //  int n = 2, m = 1;
  //  vector<int> hBars = {2, 3};
  //  vector<int> vBars = {2};
  int n = 1, m = 1;
  vector<int> hBars = {2};
  vector<int> vBars = {2};
  Solution solution;
  cout << solution.maximizeSquareHoleArea(n, m, hBars, vBars) << endl;
  return 0;
}