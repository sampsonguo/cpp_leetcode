//
// Created by sigmoidguo on 2023/12/16.
//

#include <bits/stdc++.h>
using namespace std;

/**
 *2933. 高访问员工
 *https://leetcode.cn/contest/weekly-contest-371/problems/high-access-employees/
 */
class Solution {
public:
  bool in_an_hour(string a, string b) {
    int ah = stoi(a.substr(0, 2));
    int bh = stoi(b.substr(0, 2));
    int am = stoi(a.substr(2, 2));
    int bm = stoi(b.substr(2, 2));
    return (bh - ah == 1 && bm - am < 0) || (bh - ah == 0 && bm - am <= 59);
  }
  vector<string> findHighAccessEmployees(vector<vector<string>> &access_times) {
    map<string, vector<string>> m;
    for (int i = 0; i < access_times.size(); i++) {
      string name = access_times[i][0];
      string hour = access_times[i][1];
      m[name].push_back(hour);
    }
    vector<string> ret;
    for (auto it = m.begin(); it != m.end(); it++) {
      sort(it->second.begin(), it->second.end());
      vector<string> v;
      for (int i = 0; i < it->second.size(); i++) {
        v.push_back(it->second[i]);
      }
      for (int i = 2; i < v.size(); i++) {
        if (in_an_hour(v[i - 2], v[i])) {
          ret.push_back(it->first);
          break;
        }
      }
    }
    return ret;
  }
};

int main() {
  vector<vector<string>> access_times = {{"a", "0549"},
                                         {"b", "0457"},
                                         {"a", "0532"},
                                         {"a", "0621"},
                                         {"b", "0540"}};
  Solution solution;
  vector<string> ret = solution.findHighAccessEmployees(access_times);
  for (int i = 0; i < ret.size(); i++) {
    cout << ret[i] << " ";
  }
  cout << endl;
  return 0;
}