#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
      if (!head) return false;
      for (ListNode* slow = head, *fast = head->next; fast and fast->next; slow = slow->next, fast = fast->next->next) {
        if (fast == slow) return true;
      }
      return false;
    }
};

int main()
{
  Solution s;

  ListNode* head = new ListNode(3);
  head->next = new ListNode(2);
  head->next->next = new ListNode(0);
  head->next->next->next = new ListNode(-4);
  head->next->next->next->next = head->next;
  cout << "head = [3,2,0,-4], pos = 1 => true: " << s.hasCycle(head) << endl;

  ListNode* head2 = new ListNode(1);
  head2->next = new ListNode(2);
  head2->next->next = head2;
  cout << "head = [1,2], pos = 0 => true: " << s.hasCycle(head2) << endl;

  ListNode* head3 = new ListNode(1);
  cout << "head = [1], pos = -1 => false: " << s.hasCycle(head3) << endl;

  ListNode* head4 = nullptr;
  cout << "head = [], pos = -1 => false: " << s.hasCycle(head4) << endl;

  return 0;
}
