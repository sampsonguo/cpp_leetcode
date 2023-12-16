//
// Created by sigmoidguo on 2023/12/10.
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int numberOfGoodPartitions(vector<int>& nums) {
    // 用于存放每一个线段
    vector<vector<int>> vvi;

    // 记录每种数字开始和结束的位置
    unordered_map<int, pair<int, int>> m;
    for(int i = 0; i < nums.size(); i++) {
      if(m.find(nums[i]) == m.end()) { // 没找到则记录第一次出现的位置，即开始点
        m[nums[i]].first = i;
      } else { // 找到了则更新结束的位置
        m[nums[i]].second = i;
      }
    }

    // 用于存储正处于多少线段的中间
    set<int> s;

    long long cnt = 0; // 记录有多少段
    long long ret = 1;
    long long mod = 1000000000+7;
    for(int i = 0; i < nums.size(); i++) {
      // 拿到该数字的起始点和结束点
      int st = m[nums[i]].first;
      int ed = m[nums[i]].second;

      // 如果还没到结束点，加入该线段
      if(i < ed) {
        s.insert(nums[i]);
      }
      // 如果到了结束点，去掉该线段
      if(i >= ed) {
        s.erase(nums[i]);
      }
      // 如果集合是空的，代表以i为结尾的这一段，是可以独立的
      if(s.size() == 0) cnt++;
    }
    // cout << ".. " << cnt << endl;

    for(int i = 0; i < cnt-1; i++) {
      ret *= 2;
      ret %= mod;
    }
    return ret;
  }
};

int main() {
  vector<int> nums = {2,2,2,2,5,5,5,8};
  Solution solution;
  cout << solution.numberOfGoodPartitions(nums) << endl;
  return 0;
}