//
// Created by sigmoidguo on 2023/12/14.
//

#include <bits/stdc++.h>
using namespace std;

/**
 * 题目: 2942. 查找包含给定字符的单词
 * 链接:https://leetcode.cn/contest/biweekly-contest-118/problems/find-words-containing-character/
 * 思路: 遍历
 */
class Solution {
public:
  static bool contains(string &word, char x) {
    for (int i = 0; i < word.size(); i++) {
      if (word[i] == x) {
        return true;
      }
    }
    return false;
  }
  vector<int> findWordsContaining(vector<string> &words, char x) {
    vector<int> ret;
    for (int i = 0; i < words.size(); i++) {
      if (contains(words[i], x)) {
        ret.push_back(i);
      }
    }
    return ret;
  }
};

int main() {
  vector<string> words = {"leet", "code"};
  char x = 'e';
  Solution solution;
  vector<int> ret = solution.findWordsContaining(words, x);
  for (int i = 0; i < ret.size(); i++) {
    cout << ret[i] << " ";
  }
  cout << endl;
  return 0;
}