//
// Created by sigmoidguo on 2023/12/13.
//

#include <bits/stdc++.h>
using namespace std;

/**
 * 题目:2959. 关闭分部的可行集合数目
 * 链接:https://leetcode.cn/problems/number-of-possible-sets-of-closing-branches/description/
 * 思路:
 * 1.如果要计算最短距离不超过maxDistance，就需要知道两两点之间的距离，n个点，floyd算法复杂度O(n^3)
 * 2.如果判断某些点参与计算，某些点不参与计算，最简单是用二进制来表示，n<=10，所以最大值是2^10=1024，并不大
 * 3.对于一些情况的计算，是可以复用的，也就是可以DP的，例如新增加一个点，那新图并不需要全部进行floyd，只需要对于增加的点进行floyd即可
 * 4.对于增加的一个点的情况来说，可能使得最短路径变大，也可能使得最短路径变小
 * 5.思考floyd算法
 * for (int k = 0; k < n; k++) {
 *  for (int i = 0; i < n; i++) {
 *  for (int j = 0; j < n; j++) {
 *  if (d[i][j] > d[i][k] + d[k][j]) {
 *  d[i][j] = d[i][k] + d[k][j];
 *  }
 *  }
 *  }
 * 本质上是需要知道f[m][i][j]的所有值,也就是说m代表的是2^10种点的情况
 * 此时如果不经过优化，复杂度是O(2^n*n^3)
 * 而如上述所说，如果考虑m本身是逐渐增加的情况，也就是说m的图是变得越来越大的，这时候其实只需要考虑新点对于原来的图的影响情况
 * 也就是新点是"k"，这个k对旧图的所有i和j点进行一轮“松弛”操作
 * 6. 所以步骤为:
 *  * 1.枚举压缩状态m
 *  * 2.对于m的二进制(假设01001100)种的每一个1,都可进行一轮dp，也就是当做k来对之前的点进行松弛操作
 *  * 3.计数该m是否满足要求
 */

class Solution {
public:
  int numberOfSets(int n, int maxDistance, vector<vector<int>> &roads) {
    // 距离矩阵d
    vector<vector<vector<int>>> d;

    // 使用roads初始化d

    // 首先遍历地图，这里需要保留一个性质，后面的m一定要比前面的m多一些点,
    // 也就是符合dp属性
    for (int m = 0; m < (1 << n); m++) {
      // 从左向右将m的每一位取出来
      for (int mi = 0; mi < n; mi++) {
        // 获取对应的点p，也就是需要新增加的k点
        int p = m & (1 << mi);
        if (p == 1) {
          for (int i = 0; i < mi; i++) {
            for (int j = 0; j < mi; j++) {
              // [0, mi]这一段构成的子图
              int m2 = (m >> (n - 1 - mi)) << (n - 1 - mi);
              d[m2][i][j] = min(d[m2][i][j], d[m2][i][mi] + d[m2][mi][j]);
            }
          }
        }
      }
    }
  }
};