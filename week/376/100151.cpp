//
// Created by sigmoidguo on 2023/12/17.
//

#include <bits/stdc++.h>
using namespace std;

/**
 * 0. 首先排序
 * 1. 一位数都是回文, 1,2,3...9
 * 2. 两位数, 11,22,33..,99
 * 3. 三位数, 101,111,121,...
 * 4. 范围[x,y]种是否存在回文数呢?
 */

// 打表形式生成所有的回文数
vector<long long> all_palindromes;
auto init = [] {
  // 偶数
  for (int i = 1; i < 10010; i++) {
    long long now = i;
    long long final = i;
    while (now > 0) {
      final *= 10;
      final += now % 10;
      now /= 10;
    }
    all_palindromes.push_back(final);
  }

  // 奇数
  for (int i = 0; i < 10010; i++) {
    for (int mid = 0; mid <= 9; mid++) {
      long long now = i;
      long long final = i;
      final *= 10;
      final += mid;
      while (now > 0) {
        final *= 10;
        final += now % 10;
        now /= 10;
      }
      all_palindromes.push_back(final);
    }
  }
  sort(all_palindromes.begin(), all_palindromes.end());
  return 0;
}();

class Solution {
public:
  static int make_param_left(int the_num, vector<long long> &all_palindromes) {
    return (int)*--upper_bound(all_palindromes.begin(), all_palindromes.end(),
                               the_num);
  }

  static int make_param_right(int the_num, vector<long long> &all_palindromes) {
    return (int)*lower_bound(all_palindromes.begin(), all_palindromes.end(),
                             the_num);
  }

  long long calc(vector<int> &nums, int the_num) {
    long long ret = 0;
    for (int i = 0; i < nums.size(); i++) {
      ret += abs(nums[i] - the_num);
    }
    return ret;
  }

  long long minimumCost(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int mid = n / 2;
    int l, r;
    int the_num_left, the_num_right;

    // 偶数个数字
    if (n % 2 == 0) {
      l = nums[mid - 1];
      r = nums[mid];
    } else { // 奇数个数字
      l = nums[mid];
      r = nums[mid];
    }
    the_num_left = make_param_left(r, all_palindromes);
    the_num_right = make_param_right(l, all_palindromes);
    long long the_left_ans = calc(nums, the_num_left);
    long long the_right_ans = calc(nums, the_num_right);
    return min(the_left_ans, the_right_ans);
  }
};

int main() {
  //  vector<int> nums = {1, 2, 3, 4, 5};
  //  vector<int> nums = {10, 12, 13, 14, 15};
  //  vector<int> nums = {22, 33, 22, 33, 22};
  //  vector<int> nums = {3, 2};
  //  vector<int> nums = {301, 309, 312, 322};
  vector<int> nums = {279, 578, 993, 142, 326, 673, 257, 497,
                      405, 455, 849, 789, 105, 664, 972};
  Solution solution;
  cout << solution.minimumCost(nums) << endl;
  return 0;
  //  Solution solution;
  //  vector<long long> nums = {105, 142, 257, 279, 326, 405, 494, 505,
  //                            578, 664, 673, 789, 849, 972, 993};
  //  cout << solution.make_param_left(497, nums) << endl;
}