
#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *removeNodes(ListNode *head) {
    ListNode *original_head = head;
    ListNode *move_head = head;
    vector<int> nums;
    while (head != nullptr) {
      nums.push_back(head->val);
      head = head->next;
    }
    int n = nums.size();
    int mmax = nums[n - 1];
    for (int i = nums.size() - 1; i >= 0; i--) {
      nums[i] = max(nums[i], mmax);
      mmax = max(mmax, nums[i]);
    }
    int cnt = 1;
    while (move_head->next != nullptr) {
      // 右侧有更大的值
      if (move_head->next->val < nums[cnt]) {
        // 删除一个值
        move_head->next = move_head->next->next;
      } else {
        move_head = move_head->next;
      }
      cnt++;
    }
    if (original_head->val < nums[0]) {
      return original_head->next;
    }
    return original_head;
  }
};

int main() {
  Solution solution;
  ListNode *head = new ListNode(5);
  ListNode *node1 = new ListNode(2);
  ListNode *node2 = new ListNode(13);
  ListNode *node3 = new ListNode(3);
  ListNode *node4 = new ListNode(8);
  //  ListNode *head = new ListNode(138);
  //  ListNode *node1 = new ListNode(466);
  //  ListNode *node2 = new ListNode(216);
  //  ListNode *node3 = new ListNode(67);
  //  ListNode *node4 = new ListNode(642);
  //  ListNode *head = new ListNode(998);
  //  ListNode *node1 = new ListNode(961);
  //  ListNode *node2 = new ListNode(943);
  //  ListNode *node3 = new ListNode(920);
  //  ListNode *node4 = new ListNode(698);
  head->next = node1;
  node1->next = node2;
  node2->next = node3;
  node3->next = node4;
  ListNode *ans = solution.removeNodes(head);
  while (ans != nullptr) {
    cout << ans->val << endl;
    ans = ans->next;
  }
}