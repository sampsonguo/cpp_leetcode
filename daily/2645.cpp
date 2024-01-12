
#include <bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.cn/problems/minimum-additions-to-make-valid-string/?envType=daily-question&envId=2024-01-11
 */
class Solution {
public:
  int addMinimum(string word) {
    int seg = 0;
    for (int i = 1; i < word.size(); i++) {
      if (word[i] <= word[i - 1]) {
        seg++;
      }
    }
    return (seg + 1) * 3 - word.size();
  }
};

int main() {
  cout << Solution().addMinimum("b") << endl;
  cout << Solution().addMinimum("aaa") << endl;
  cout << Solution().addMinimum("abc") << endl;
}
