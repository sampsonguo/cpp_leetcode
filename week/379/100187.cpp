
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool be(int a, int b, int c) {
    int mi = min(b, c);
    int ma = max(b, c);
    if (a > mi && a < ma) {
      return true;
    }
    return false;
  }
  int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
    // 0次
    if (a == e && b == f) {
      return 0;
    }

    if (c == e && d == f) {
      return 0;
    }

    // 1次, 同行
    if (a == e) {
      // 不存在象挡在车和皇后之间
      if (!(c == a && be(d, b, f))) {
        return 1;
      } else {
        return 2;
      }
    }

    // 1次，同列
    if (b == f) {
      if (!(d == b && be(c, a, e))) {
        return 1;
      } else {
        return 2;
      }
    }

    // 1次，同斜线-左上到右下
    if (c - d == e - f) {
      // 不存在车挡在象和皇后之间
      if (!(a - b == c - d && be(a, c, e))) {
        return 1;
      } else {
        return 2;
      }
    }

    // 1次，同斜线-右上到左下
    if (c + d == e + f) {
      if (!(a + b == c + d && be(a, c, e))) {
        return 1;
      } else {
        return 2;
      }
    }

    return 2;
  }
};

int main() {
  Solution solution;
  cout << solution.minMovesToCaptureTheQueen(1, 1, 8, 8, 2, 3) << endl; // 2
  cout << solution.minMovesToCaptureTheQueen(5, 3, 3, 4, 5, 2) << endl; // 1
  cout << solution.minMovesToCaptureTheQueen(1, 1, 3, 1, 5, 1) << endl;
  cout << solution.minMovesToCaptureTheQueen(1, 1, 1, 4, 1, 8) << endl;
}