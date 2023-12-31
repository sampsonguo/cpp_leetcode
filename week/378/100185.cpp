
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int calc(vector<int> &v) {
    // 由大到小排序
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    int sum = accumulate(v.begin(), v.end(), 0);

    // 不成立
    if (sum < 3) {
      return -1;
    }

    // 有三个最大的相同
    if (v.size() >= 3 && v[0] == v[1] && v[1] == v[2]) {
      return v[0];
    }

    // 最大的拆分为2个之后，和排名第二的相同
    if (v.size() >= 2 && v[0] - 1 <= v[1]) {
      return v[0] - 1;
    }

    // 最大的拆分为3个,返回
    if (v.size() >= 1 && v[0] >= 3) {
      return v[0] - 2;
    }

    return -1;
  }

  int maximumLength(string s) {
    // 字母 -> 次数
    unordered_map<char, vector<int>> m;
    for (int i = 0; i < s.size(); i++) {
      // 和上一个字母一样
      if (i > 0 && s[i] == s[i - 1]) {
        m[s[i]].back()++;
      } else {
        // 新字母
        m[s[i]].push_back(1);
      }
    }
    int ans = -1;
    for (auto it = m.begin(); it != m.end(); it++) {
      ans = max(ans, calc(it->second));
    }
    return ans;
  }
};

int main() {
  Solution solution;
  cout << solution.maximumLength("aaaa") << endl;
  cout << solution.maximumLength("abcdef") << endl;
  cout << solution.maximumLength("abcaba") << endl;
  cout << solution.maximumLength("ceeeeeeeeeeeebmmmfffeeeeeeeeeeeewww")
       << endl; // 预期11
}