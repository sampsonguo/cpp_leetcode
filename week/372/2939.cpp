//
// Created by sigmoidguo on 2023/12/15.
//

#include <bits/stdc++.h>
using namespace std;

/**
 * 2939. 最大异或乘积
 * https://leetcode.cn/contest/weekly-contest-372/problems/maximum-xor-product/
 * 1. a和b均展开成长度为n的二进制串
 * 2. 如果某位a和b均为1，则x的该位置取0
 * 3. 如果某位a和b均为0，则x的该位置取1
 * 4. 如果某位a和b有一个为1，有一个为0，那么x取值另较小的一个为1，较大的一个为0
 * 5. 得到新a和新b
 * 6. 计算结果
 */

class Solution {
public:
  long long maximumXorProduct(long long a, long long b, long long n) {
    for (long long i = n - 1; i >= 0; i--) {
      long long ai = (a >> i) & 1LL;
      long long bi = (b >> i) & 1LL;
      if (ai != bi) {
        if (a > b) {
          b = b | (1LL << i);
          a = a & (~(1LL << i));
        } else {
          a = a | (1LL << i);
          b = b & (~(1LL << i));
        }
      } else {
        a = a | (1LL << i);
        b = b | (1LL << i);
      }
    }
    //    cout << a << " " << b << endl;
    long long MOD = 1e9 + 7;
    return (a % MOD) * (b % MOD) % MOD;
  }
};

int main() {
  long long a = 12, b = 5;
  int n = 4;
  //  long long a = 6, b = 7;
  //  int n = 5;
  //  long long a = 1, b = 6;
  //  int n = 3;
  Solution solution;
  cout << solution.maximumXorProduct(a, b, n) << endl;
  return 0;
}