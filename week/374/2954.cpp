//
// Created by sigmoidguo on 2023/12/22.
//

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  static const int mod = 1e9 + 7;
  int f[1000010];
  int init(int n, int p) {
    f[0] = 1;
    for (int i = 1; i < 1000005; i++) {
      f[i] = (f[i - 1] * i) % p;
    }
  }
  static int fastpow(int a, int b, int p) {
    int ans = 1;
    while (b) {
      if (b & 1) {
        ans = ans * a % p;
      }
      a = a * a % p;
      b >>= 1;
    }
    return ans;
  }
  static int inv(int a, int p) { return fastpow(a, p - 2, p); }
  int C(int n, int m, int p) {
    return f[n] * inv(f[m], p) % p * inv(f[n - m], p) % p;
  }
  int lucas(int n, int m, int p) {
    if (m == 0) {
      return 1;
    }
    // optimize with Lucas theorem
    return (C(n % p, m % p, p) * lucas(n / p, m / p, p)) % p;
  }
  int numberOfSequence(int n, vector<int> &sick) {
    long long ans = 1;
    init(n, mod);
    cout << C(2, 2, mod) << endl;
    cout << C(2, 1, mod) << endl;
    cout << C(3, 0, mod) << endl;
    cout << C(3, 1, mod) << endl;
    cout << C(3, 2, mod) << endl;
    cout << C(3, 3, mod) << endl;
    cout << lucas(3, 2, mod) << endl;
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
        ans = ans * fastpow(2, gap - 1, mod) % mod;
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
      int cc = C(total - acc, v[i], mod);
      ans += cc;
      ans %= mod;
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