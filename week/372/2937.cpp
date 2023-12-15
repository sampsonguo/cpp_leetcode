//
// Created by sigmoidguo on 2023/12/15.
//

#include <iostream>
using namespace std;

/**
 * 2937. 使三个字符串相等
 * https://leetcode.cn/contest/weekly-contest-372/problems/make-three-strings-equal/
 */
class Solution {
public:
  int findMinimumOperations(string s1, string s2, string s3) {
    int cnt = 0;
    for (int i = 0; i < s1.size() && i < s2.size() && i < s3.size(); i++) {
      if (s1[i] == s2[i] && s2[i] == s3[i]) {
        cnt++;
      } else {
        break;
      }
    }
    if (cnt == 0) {
      return -1;
    }
    return s1.size() + s2.size() + s3.size() - 3 * cnt;
  }
};

int main() {
  string s1 = "abc", s2 = "abb", s3 = "ab";
  //  string s1 = "dac", s2 = "bac", s3 = "cac";
  Solution solution;
  cout << solution.findMinimumOperations(s1, s2, s3) << endl;
  return 0;
}