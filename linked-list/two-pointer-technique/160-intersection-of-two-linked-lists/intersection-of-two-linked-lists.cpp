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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      int sizeA = 1, sizeB = 1;
      ListNode* tailA, *tailB;
      for (tailA = headA; tailA->next; tailA = tailA->next, ++sizeA);
      for (tailB = headB; tailB->next; tailB = tailB->next, ++sizeB);
      if (tailA != tailB) return nullptr;
      ListNode* shorter = sizeA < sizeB ? headA : headB;
      ListNode* longer = sizeA < sizeB ? headB : headA;
      for (int i = 0; i < abs(sizeA - sizeB); ++i, longer = longer->next);
      for (; shorter != longer; shorter = shorter->next, longer = longer->next);
      return shorter;
    }
};

int main()
{
  Solution s;

  ListNode* headA = new ListNode(4);
  headA->next = new ListNode(1);
  headA->next->next = new ListNode(8);
  headA->next->next->next = new ListNode(4);
  headA->next->next->next->next = new ListNode(5);

  ListNode* headB = new ListNode(5);
  headB->next = new ListNode(6);
  headB->next->next = new ListNode(1);
  headB->next->next->next = headA->next->next;

  cout << "intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3 => 8: " << s.getIntersectionNode(headA, headB)->val << endl; 

  ListNode* headA2 = new ListNode(1);
  headA2->next = new ListNode(9);
  headA2->next->next = new ListNode(1);
  headA2->next->next->next = new ListNode(2);
  headA2->next->next->next->next = new ListNode(4);

  ListNode* headB2 = new ListNode(3);
  headB2->next = headA2->next->next->next;

  cout << "intersectVal = 2, listA = [1,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1 => 2: " << s.getIntersectionNode(headA2, headB2)->val << endl;

  ListNode* headA3 = new ListNode(2);
  headA3->next = new ListNode(6);
  headA3->next->next = new ListNode(4);

  ListNode* headB3 = new ListNode(1);
  headB3->next = new ListNode(5);

  cout << "intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2 => nullptr: " << s.getIntersectionNode(headA3, headB3) << endl;

  ListNode* headA4 = new ListNode(100000);
  ListNode* headB4 = new ListNode(100000);
  cout << "intersectVal = 0, listA = [100000], listB = [100000], skipA = 1, skipB = 1 => nullptr: " << s.getIntersectionNode(headA4, headB4) << endl;

  ListNode* headA5 = new ListNode(100000);
  ListNode* headB5 = headA5;
  cout << "intersectVal = 100000, listA = [100000], listB = [100000], skipA = 0, skipB = 0 => 100000: " << s.getIntersectionNode(headA5, headB5)->val << endl;

  return 0;
}
