
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
  ListNode *insertGreatestCommonDivisors(ListNode *head) {
    ListNode *move_head1 = head;
    ListNode *move_head2 = head;

    // 如果链表长度为1
    if (head->next == nullptr) {
      return head;
    }

    // 如果链表长度为2以上, move_head11在左侧，move_head2在右侧
    move_head2 = move_head2->next;
    while (move_head2 != nullptr) {
      ListNode *in = new ListNode();
      in->val = __gcd(move_head1->val, move_head2->val);
      in->next = move_head2;
      move_head1->next = in;
      move_head1 = move_head2;
      move_head2 = move_head2->next;
    }

    return head;
  }
};

int main() {
  Solution solution;
  ListNode *head = new ListNode(18);
  ListNode *node1 = new ListNode(6);
  ListNode *node2 = new ListNode(10);
  ListNode *node3 = new ListNode(3);
  head->next = node1;
  node1->next = node2;
  node2->next = node3;
  ListNode *ans = solution.insertGreatestCommonDivisors(head);
  while (ans != nullptr) {
    cout << ans->val << " ";
    ans = ans->next;
  }
  cout << endl;
}