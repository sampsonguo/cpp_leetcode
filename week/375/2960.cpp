//
// Created by sigmoidguo on 2023/12/13.
//

#include <bits/stdc++.h>
using namespace std;

//
// https://leetcode.cn/problems/count-tested-devices-after-test-operations/description/

class Solution {
public:
  int countTestedDevices(vector<int>& batteryPercentages) {
    vector<int>& v = batteryPercentages;
    // 对于每一个电池
    int ret = 0;
    for(int i = 0; i < v.size(); i++) {
      if(v[i] > 0) ret++;
      else continue;
      for(int j = i+1; j < v.size(); j++) {
        v[j]--;
      }
    }
    return ret;
  }
};

int main() {
  vector<int> batteryPercentages = {1,1,2,1,3};
  Solution solution;
  cout << solution.countTestedDevices(batteryPercentages) << endl;
  return 0;
}