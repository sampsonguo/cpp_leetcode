
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool canConstruct(string ransomNote, string magazine) {
    unordered_map<char, int> m;
    for (int i = 0; i < magazine.size(); i++) {
      m[magazine[i]]++;
    }
    for (int i = 0; i < ransomNote.size(); i++) {
      if (m.find(ransomNote[i]) == m.end()) {
        return false;
      }
      if (m[ransomNote[i]] == 0) {
        return false;
      }
      m[ransomNote[i]]--;
    }
    return true;
  }
};