//
// Created by sigmoidguo on 2023/12/15.
//

#include <bits/stdc++.h>
using namespace std;

/**
 * 2938. 区分黑球与白球
 * https://leetcode.cn/contest/weekly-contest-372/problems/separate-black-and-white-balls/
 */
class Solution {
public:
  long long minimumSteps(string s) {
    vector<int> v;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == '0') {
        v.push_back(i);
      }
    }
    long long ret = 0;
    for (int i = 0; i < v.size(); i++) {
      ret += abs(v[i] - i);
    }
    return ret;
  }
};

int main() {
  //  string s = "101";
  //  string s = "100";
  string s = "0111";
  Solution solution;
  cout << solution.minimumSteps(s) << endl;
  return 0;
}