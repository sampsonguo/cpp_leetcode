
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int maximumSetSize(vector<int> &nums1, vector<int> &nums2) {
    //    int n = nums1.size();
    //    sort(nums1.begin(), nums1.end());
    //    sort(nums2.begin(), nums2.end());
    //    nums1.erase(unique(nums1.begin(), nums1.end()), nums1.end());
    //    nums2.erase(unique(nums2.begin(), nums2.end()), nums2.end());
    //    // s1从小到大
    //    // s2从大到小
    //    sort(nums1.begin(), nums1.end());
    //    sort(nums2.begin(), nums2.end());
    //    reverse(nums2.begin(), nums2.end());
    //    vector<int> ans;
    //    for (int i = 0; i < nums1.size() && i < n / 2; i++) {
    //      ans.push_back(nums1[i]);
    //      ans.push_back(nums2[i]);
    //    }
    //    sort(ans.begin(), ans.end());
    //    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    //    return ans.size();
    int n = nums1.size();
    unordered_set<int> s1, s2, ans;
    for (int i = 0; i < nums1.size(); i++) {
      s1.insert(nums1[i]);
    }
    for (int i = 0; i < nums2.size(); i++) {
      s2.insert(nums2[i]);
    }
    // num1和num2取交集
    vector<int> v;
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(),
                     back_inserter(v));
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    // 取s1独有的数字，最多一半
    int cnt = 0;
    for (auto it = s1.begin(); it != s1.end() && cnt < n / 2; it++) {
      if (s2.find(*it) == s2.end()) {
        ans.insert(*it);
        cnt++;
      }
    }
    // 取s1和s2共有的数字，从小到大，最多一半
    for (int i = 0; i < v.size() && cnt < n / 2; i++) {
      ans.insert(v[i]);
      cnt++;
    }

    // 取s2独有的数字，最多一半
    cnt = 0;
    for (auto it = s2.begin(); it != s2.end() && cnt < n / 2; it++) {
      if (s1.find(*it) == s1.end()) {
        ans.insert(*it);
        cnt++;
      }
    }
    // 取s1和s2共有的数字，从大到小，最多一半
    for (int i = v.size() - 1; i >= 0 && cnt < n / 2; i--) {
      ans.insert(v[i]);
      cnt++;
    }
    return ans.size();
  }
};

int main() {
  Solution solution;
  vector<int> nums1 = {1, 2, 1, 2};
  vector<int> nums2 = {1, 1, 1, 1};
  //  vector<int> nums1 = {1, 2, 3, 4, 5, 6};
  //  vector<int> nums2 = {2, 3, 2, 3, 2, 3};
  //  vector<int> nums1 = {1, 1, 2, 2, 3, 3};
  //  vector<int> nums2 = {4, 4, 5, 5, 6, 6};
  //  vector<int> nums1 = {7, 2, 5, 1, 3, 1, 4, 5};
  //  vector<int> nums2 = {1, 5, 5, 9, 1, 6, 4, 1};
  cout << solution.maximumSetSize(nums1, nums2) << endl;
}