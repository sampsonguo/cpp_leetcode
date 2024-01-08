
#include <bits/stdc++.h>
using namespace std;

// acbacbacbacb
// abab

// acb
// acb
class Solution {
public:
  int getMaxRepetitions(string s1, int n1, string s2, int n2) {

    int l1 = s1.length();
    int l2 = s2.length();

    int p1 = 0;
    int p2 = 0;
    while (p1 < l1 * l2) {
      if (s1[p1 % l1] == s2[p2 % l2]) {
        p1++;
        p2++;
      } else {
        p1++;
      }
    }
    int old_p2 = p2;

    p1 = 0;
    p2 = 0;
    while (p1 < ((l1 * n1) % (l1 * l2)))
      if (s1[p1 % l1] == s2[p2 % l2]) {
        p1++;
        p2++;
      } else {
        p1++;
      }
    int other = p2 / (l2 * n2);

    return old_p2 * n1 / (l2 * n2 * l2) + other;
  }
};

int main() {
  Solution solution;
  //  cout << solution.getMaxRepetitions("acb", 4, "ab", 2) << endl;
  cout << solution.getMaxRepetitions("acb", 1, "acb", 1) << endl;
  //  cout << solution.getMaxRepetitions("baba", 11, "baab", 1) << endl;
  //  cout << solution.getMaxRepetitions("lovelive", 1000, "lovelive", 999) <<
  //  endl;
};