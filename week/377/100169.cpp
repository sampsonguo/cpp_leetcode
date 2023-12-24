
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int maximizeSquareArea(int m, int n, vector<int> &hFences,
                         vector<int> &vFences) {
    sort(hFences.begin(), hFences.end());
    sort(vFences.begin(), vFences.end());
    hFences.insert(hFences.begin(), 1);
    hFences.push_back(m);
    vFences.insert(vFences.begin(), 1);
    vFences.push_back(n);
    set<int> hSet, vSet;
    for (int i = 0; i < hFences.size(); i++) {
      for (int j = i + 1; j < hFences.size(); j++) {
        hSet.insert(hFences[j] - hFences[i]);
      }
    }
    for (int i = 0; i < vFences.size(); i++) {
      for (int j = i + 1; j < vFences.size(); j++) {
        vSet.insert(vFences[j] - vFences[i]);
      }
    }
    //    set<int> S;
    //    set_intersection(hSet.begin(), hSet.end(), vSet.begin(), vSet.end(),
    //                     inserter(S, S.end()));

    long long ans = -1;
    long long MOD = 1e9 + 7;
    for (auto x : hSet) {
      if (vSet.count(x)) {
        ans = max(ans, x * 1LL * x);
      }
    }
    return int(ans % MOD);
  }
};

int main() {
  Solution solution;
  //  int m = 4, n = 3;
  //  vector<int> hFences = {2, 3}, vFences = {2};
  //  int m = 6, n = 7;
  //  vector<int> hFences = {2}, vFences = {4};
  int m = 3, n = 9;
  vector<int> hFences = {2}, vFences = {8, 6, 5, 4};
  cout << solution.maximizeSquareArea(m, n, hFences, vFences) << endl;
}