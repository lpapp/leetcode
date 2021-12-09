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
    ListNode *detectCycle(ListNode *head) {
      if (!head or !head->next) return nullptr;
      ListNode* slow = head->next;
      for (ListNode* fast = head->next->next; fast != slow; fast = fast->next->next, slow = slow->next) if (!fast or !fast->next) return nullptr;
      for (ListNode* fast = head; fast != slow; fast = fast->next, slow = slow->next);
      return slow;
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
  cout << "head = [3,2,0,-4], pos = 1 => 2: " << s.detectCycle(head)->val << endl;

  ListNode* head2 = new ListNode(1);
  head2->next = new ListNode(2);
  head2->next->next = head2;
  cout << "head = [1,2], pos = 0 => 1: " << s.detectCycle(head2)->val << endl;

  ListNode* head3 = new ListNode(1);
  cout << "head = [1], pos = -1 => nullptr: " << s.detectCycle(head3) << endl;

  ListNode* head4 = nullptr;
  cout << "head = [], pos = -1 => nullptr: " << s.detectCycle(head4) << endl;

  return 0;
}
