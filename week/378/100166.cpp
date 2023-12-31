
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool hasTrailingZeros(vector<int> &nums) {
    int cnt = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] % 2 == 0) {
        cnt++;
      }
    }
    return cnt >= 2;
  }
};