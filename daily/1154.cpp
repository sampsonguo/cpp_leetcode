
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int dayOfYear(string date) {
    int year = stoi(date.substr(0, 4));
    int month = stoi(date.substr(5, 2));
    int day = stoi(date.substr(8, 2));
    int ans = 0;
    for (int i = 1; i < month; i++) {
      if (i == 2) {
        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
          ans += 29;
        } else {
          ans += 28;
        }
      } else if (i == 4 || i == 6 || i == 9 || i == 11) {
        ans += 30;
      } else {
        ans += 31;
      }
    }
    ans += day;
    return ans;
  }
};