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
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      ListNode* added = nullptr, *head = nullptr;
      for (int value = 0; l1 or l2 or value; value /= 10) {
        if (l1) { value += l1->val; l1 = l1->next; }
        if (l2) { value += l2->val; l2 = l2->next; }
        if (added) { added->next = new ListNode(value % 10); added = added->next; }
        else { added = new ListNode(value % 10); head = added; }
      }
      return head;
    }
};

void test(ListNode* list1, ListNode* list2)
{
  Solution s;

  cout << "[";
  for (ListNode* h = s.addTwoNumbers(list1, list2); h; h = h->next) cout << h->val << ",";
  cout << "]" << endl;
}

int main()
{
  ListNode* list1 = new ListNode(2);
  list1->next = new ListNode(4);
  list1->next->next = new ListNode(3);

  ListNode* list2 = new ListNode(5);
  list2->next = new ListNode(6);
  list2->next->next = new ListNode(4);
  cout << "[2,4,3] | [5,6,4] => [7,0,8]: ";

  test(list1, list2);

  ListNode* list1_1 = new ListNode(0);
  ListNode* list2_1 = new ListNode(0);
  cout << "[0] | [0] => [0]: ";
  test(list1_1, list2_1);

  ListNode* list1_2 = new ListNode(9);
  list1_2->next = new ListNode(9);
  list1_2->next->next = new ListNode(9);
  list1_2->next->next->next = new ListNode(9);
  list1_2->next->next->next->next = new ListNode(9);
  list1_2->next->next->next->next->next = new ListNode(9);
  list1_2->next->next->next->next->next->next = new ListNode(9);

  ListNode* list2_2 = new ListNode(9);
  list2_2->next = new ListNode(9);
  list2_2->next->next = new ListNode(9);
  list2_2->next->next->next = new ListNode(9);

  cout << "[9,9,9,9,9,9,9] | [9,9,9,9] => [8,9,9,9,0,0,0,1]: ";
  test(list1_2, list2_2);

  cout << "[9,9,9,9] | [9,9,9,9,9,9,9] => [8,9,9,9,0,0,0,1]: ";
  test(list2_2, list1_2);

  return 0;
}
