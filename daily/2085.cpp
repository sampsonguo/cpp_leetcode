
#include <bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.cn/problems/count-common-words-with-one-occurrence/?envType=daily-question&envId=2024-01-12
 */
class Solution {
public:
  int countWords(vector<string> &words1, vector<string> &words2) {
    unordered_map<string, int> m1, m2;
    for (int i = 0; i < words1.size(); i++) {
      m1[words1[i]]++;
    }
    for (int i = 0; i < words2.size(); i++) {
      m2[words2[i]]++;
    }
    int ans = 0;
    for (auto it = m1.begin(); it != m1.end(); it++) {
      if (it->second == 1 && m2.find(it->first) != m2.end() &&
          m2[it->first] == 1)
        ans++;
    }
    return ans;
  }
};