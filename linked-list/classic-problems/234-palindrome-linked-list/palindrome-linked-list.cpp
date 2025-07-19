#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
class Solution {
  ListNode* reverseList(ListNode* head) {
    ListNode* new_head, *next;
    for (new_head = nullptr; head; head = next) {
      next = head->next;
      head->next = new_head;
      new_head = head;
    }
    return new_head;
  }

public:
  bool isPalindrome(ListNode* head) {
    ListNode* left_tail, *fast;
    // 1 -> 2 (s) -> 2 (f) -> 1
    // 1 -> 2 -> 3 (s) -> 2 -> 1 (f)
    // 1 -> 2 -> 3 -> 4 (s) -> 3 -> 2 -> 1 (f)
    // 1 -> 2 -> 3 (s) -> 3 -> 2 (f) -> 1
    for (left_tail = head, fast = head; fast->next and fast->next->next; left_tail = left_tail->next, fast = fast->next->next);
    for (ListNode* left = head, *right = reverseList(left_tail->next); right; left = left->next, right = right->next) if (left->val != right->val) return false;
    return true;
  }
};

int main()
{
  Solution s;

  ListNode* head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(2);
  head->next->next->next = new ListNode(1);
  cout << "[1,2,2,1] => true: " << s.isPalindrome(head) << endl;

  ListNode* head2 = new ListNode(1);
  head2->next = new ListNode(2);
  cout << "[1,2] => false: " << s.isPalindrome(head2) << endl;

  ListNode* head3 = new ListNode(1);
  cout << "[1] => true: " << s.isPalindrome(head3) << endl;

  ListNode* head4 = new ListNode(1);
  head4->next = new ListNode(2);
  head4->next->next = new ListNode(3);
  head4->next->next->next = new ListNode(2);
  head4->next->next->next->next = new ListNode(1);
  cout << "[1,2,3,2,1] => true: " << s.isPalindrome(head4) << endl;

  return 0;
}
