
#include <bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.cn/problems/construct-string-with-repeat-limit/?envType=daily-question&envId=2024-01-13
 */
class Solution {
public:
  string repeatLimitedString(string s, int repeatLimit) {
    unordered_map<char, int> m;
    for (int i = 0; i < s.size(); i++) {
      m[s[i]]++;
    }
    sort(s.begin(), s.end());
    reverse(s.begin(), s.end());
    s.erase(unique(s.begin(), s.end()), s.end());
    string ans;
    for (int i = 0; i < s.size(); i++) {
      // 如果该元素有值
      while (m[s[i]] > 0) {
        bool empty = false;
        // 每n个元素一组
        for (int j = 0; j < repeatLimit; j++) {
          if (m[s[i]] > 0) {
            ans += s[i];
            m[s[i]]--;
          } else {
            empty = true;
            break;
          }
        }
        if (m[s[i]] == 0) {
          continue;
        }
        if (i + 1 >= s.size()) {
          return ans;
        }
        bool flag = true;
        // 添加完之后，还需要找下一个能添加的元素
        for (int j = i + 1; j < s.size(); j++) {
          if (m[s[j]] > 0) {
            ans += s[j];
            m[s[j]]--;
            flag = false;
            break;
          }
        }
        if (flag) {
          return ans;
        }
      }
    }
    return ans;
  }
};

int main() {
  cout << Solution().repeatLimitedString("cczazcc", 3) << endl;
  cout << Solution().repeatLimitedString("aababab", 2) << endl;
  cout << Solution().repeatLimitedString("robnsdvpuxbapuqgopqvxdrchivlifeepy",
                                         2)
       << endl;
  cout << Solution().repeatLimitedString(
              "xyutfpopdynbadwtvmxiemmusevduloxwvpkjioizvanetecnuqbqqdtrwrkgt",
              1)
       << endl;
}