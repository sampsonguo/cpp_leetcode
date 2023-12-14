//
// Created by sigmoidguo on 2023/12/13.
//

#include <bits/stdc++.h>
using namespace std;

/**
 * 题目: 2956. 消除相邻近似相等字符
 * 链接:
 * https://leetcode.cn/contest/biweekly-contest-119/problems/remove-adjacent-almost-equal-characters/
 * 思路: DP. 从左到右遍历，如果当前字符和前一个字符近似相同，
 * 则更改为新字符，并注意新字符不能和后一个字符近似相同
 */

class Solution {
public:
  static bool appr_equal(char a, char b) { return abs(a - b) <= 1; }
  static char get_new_char(char a, char b) {
    for (char c = 'a'; c <= 'z'; c++) {
      if (!appr_equal(c, a) && !appr_equal(c, b)) {
        return c;
      }
    }
    return 'a';
  }

  int removeAlmostEqualCharacters(string word) {
    int ret = 0;
    for (int i = 1; i < word.size(); i++) {
      if (appr_equal(word[i], word[i - 1])) {
        word[i] = get_new_char(word[i - 1], word[i + 1]);
        ret++;
      }
    }
    return ret;
  }
};

int main() {
  //  string word = "aaaaa";
  string word = "zyxyxyz";
  Solution solution;
  cout << solution.removeAlmostEqualCharacters(word) << endl;
  return 0;
}