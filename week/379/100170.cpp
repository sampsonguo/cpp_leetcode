
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int areaOfMaxDiagonal(vector<vector<int>> &dimensions) {
    vector<int> dia;
    for (int i = 0; i < dimensions.size(); i++) {
      dia.push_back(dimensions[i][0] * dimensions[i][0] +
                    dimensions[i][1] * dimensions[i][1]);
    }
    sort(dia.begin(), dia.end());
    reverse(dia.begin(), dia.end());
    if (dia.size() == 1) {
      return dimensions[0][0] * dimensions[0][1];
    }
    int ans = 0;
    for (int i = 0; i < dimensions.size(); i++) {
      if (dimensions[i][0] * dimensions[i][0] +
              dimensions[i][1] * dimensions[i][1] ==
          dia[0]) {
        ans = max(ans, dimensions[i][0] * dimensions[i][1]);
      }
    }
    return ans;
  }
};

int main() {
  Solution solution;
  //  vector<vector<int>> dimensions = {{9, 3}, {8, 6}};
  vector<vector<int>> dimensions = {{3, 4}, {4, 3}};
  cout << solution.areaOfMaxDiagonal(dimensions) << endl;
}