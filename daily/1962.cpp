//
// Created by sigmoidguo on 2023/12/23.
//

#include <bits/stdc++.h>
using namespace std;

/**
 *https://leetcode.cn/problems/remove-stones-to-minimize-the-total/
 * 1. 每次需要移除最大的石头
 * 2. 石头可以用大顶堆来维护
 */
class Solution {
public:
  int minStoneSum(vector<int> &piles, int k) {
    priority_queue<int> pq;

    // 初始化堆
    for (int p : piles)
      pq.push(p);

    while (k--) {
      int cur = pq.top();
      pq.pop();
      pq.push(cur - cur / 2);
    }

    int ans = 0;
    while (!pq.empty()) {
      ans += pq.top();
      pq.pop();
    }
    return ans;
  }
};