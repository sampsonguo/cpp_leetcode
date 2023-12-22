//
// Created by sigmoidguo on 2023/12/22.
//

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  const int MOD = 1'000'000'007;
  static const int MX = 100'000;

  long long q_pow(long long x, int n) {
    long long res = 1;
    for (; n > 0; n /= 2) {
      if (n % 2) {
        res = res * x % MOD;
      }
      x = x * x % MOD;
    }
    return res;
  }

  // 组合数模板
  long long fac[MX], inv_fac[MX];

  void init() {
    fac[0] = 1;
    for (int i = 1; i < MX; i++) {
      fac[i] = fac[i - 1] * i % MOD;
    }
    inv_fac[MX - 1] = q_pow(fac[MX - 1], MOD - 2);
    for (int i = MX - 1; i > 0; i--) {
      inv_fac[i - 1] = inv_fac[i] * i % MOD;
    }
  }

  long long comb(int n, int k) {
    return fac[n] * inv_fac[k] % MOD * inv_fac[n - k] % MOD;
  }

  int numberOfSequence(int n, vector<int> &sick) {
    init();
    long long ans = 1;
    vector<int> v;
    int cnt = 0;
    sort(sick.begin(), sick.end());
    // 开头
    if (sick[0] != 0) {
      v.push_back(sick[0]);
    }
    // 中间
    for (int i = 1; i < sick.size(); i++) {
      if (sick[i] - sick[i - 1] >= 2) {
        int gap = sick[i] - sick[i - 1] - 1;
        v.push_back(gap);
        ans = ans * q_pow(2, gap - 1) % MOD;
      }
    }

    // 结尾
    if (sick[sick.size() - 1] != n - 1) {
      v.push_back(n - 1 - sick[sick.size() - 1]);
    }
    int total = accumulate(v.begin(), v.end(), 0);
    int acc = 0;
    // 线段排列
    for (int i = 0; i < v.size(); i++) {
      int cc = comb(total - acc, v[i]);
      ans *= cc;
      ans %= MOD;
      acc += v[i];
    }

    return (int)ans;
  }
};

int main() {
  //  int n = 5;
  //  vector<int> sick = {0, 4};
  int n = 4;
  vector<int> sick = {1};
  Solution solution;
  cout << solution.numberOfSequence(n, sick) << endl;
  return 0;
}