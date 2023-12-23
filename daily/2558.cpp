//
// Created by sigmoidguo on 2023/12/23.
//

#include <bits/stdc++.h>
using namespace std;

/**
 *https://leetcode.cn/problems/take-gifts-from-the-richest-pile/
 */
class Solution {
public:
  long long pickGifts(vector<int> &gifts, int k) {
    priority_queue<int> pq;

    // 初始化堆
    for (int p : gifts)
      pq.push(p);

    while (k--) {
      int cur = pq.top();
      pq.pop();
      pq.push(int(sqrt(cur)));
    }

    long long ans = 0;
    while (!pq.empty()) {
      ans += pq.top();
      pq.pop();
    }
    return ans;
  }
};