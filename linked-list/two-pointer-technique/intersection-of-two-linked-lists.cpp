#include <iostream>

using namespace std;

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
    }
};

int main()
{
  ListNode* headA = new ListNode(4);
  headA->next = new ListNode(1);
  headA->next->next = new ListNode(8);
  headA->next->next->next = new ListNode(4);
  headA->next->next->next->next = new ListNode(5);

  ListNode* headB = new ListNode(5);
  headB->next = new ListNode(6);
  headB->next->next = new ListNode(1);
  headB->next->next->next = new ListNode(8);
  headB->next->next->next->next = new ListNode(4);
  headB->next->next->next->next->next = new ListNode(5);

  cout << "intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3 => 8: " << s.getIntersectionNode(headA, headB)->val << endl; 

  ListNode* headA2 = new ListNode(1);
  headA2->next = new ListNode(9);
  headA2->next->next = new ListNode(1);
  headA2->next->next->next = new ListNode(2);
  headA2->next->next->next->next = new ListNode(4);

  ListNode* headB2 = new ListNode(3);
  headB2->next = new ListNode(2);
  headB2->next->next = new ListNode(4);

  cout << "intersectVal = 2, listA = [1,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1 => 2: " << s.getIntersectionNode(headA2, headB2)->val << endl;

  ListNode* headA3 = new ListNode(2);
  headA3->next = new ListNode(6);
  headA3->next->next = new ListNode(4);

  ListNode* headB3 = new ListNode(1);
  headB3->next = new ListNode(5);

  cout << "intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2 => nullptr: " << s.getIntersectionNode(headA3, headB3) << endl;

  return 0;
}
