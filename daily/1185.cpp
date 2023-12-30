
#include <bits/stdc++.h>
using namespace std;

/**
 *https://leetcode.cn/problems/day-of-the-week/?envType=daily-question&envId=2023-12-30
 * 1971年1月1日是星期五
 */
class Solution {
public:
  bool isLeapYear(int year) {
    if (year % 400 == 0) {
      return true;
    }
    if (year % 100 == 0) {
      return false;
    }
    if (year % 4 == 0) {
      return true;
    }
    return false;
  }

  int getDaysOfMonth(int year, int month) {
    if (month == 2) {
      if (isLeapYear(year)) {
        return 29;
      } else {
        return 28;
      }
    }
    if (month == 4 || month == 6 || month == 9 || month == 11) {
      return 30;
    }
    return 31;
  }

  string dayOfTheWeek(int day, int month, int year) {
    int days = 0;
    for (int i = 1971; i < year; i++) {
      if (isLeapYear(i)) {
        days += 366;
      } else {
        days += 365;
      }
    }
    for (int i = 1; i < month; i++) {
      days += getDaysOfMonth(year, i);
    }
    days += day;
    days--;
    int week = days % 7;
    switch (week) {
    case 0:
      return "Friday";
    case 1:
      return "Saturday";
    case 2:
      return "Sunday";
    case 3:
      return "Monday";
    case 4:
      return "Tuesday";
    case 5:
      return "Wednesday";
    case 6:
      return "Thursday";
    }
    return "";
  }
};

int main() {
  Solution solution;
  cout << solution.dayOfTheWeek(1, 1, 1971) << endl;
  cout << solution.dayOfTheWeek(31, 8, 2019) << endl;
  cout << solution.dayOfTheWeek(31, 8, 2019) << endl;
  cout << solution.dayOfTheWeek(31, 8, 2019) << endl;
  cout << solution.dayOfTheWeek(31, 8, 2019) << endl;
}