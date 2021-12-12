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
    ListNode* rotateRight(ListNode* head, int k) {
      if (!head) return head;
      ListNode* ahead = head, *beyond = head;
      for (int i = 0; i < k; ++i, ahead = ahead->next) {
        if (!ahead->next) {
          k %= i + 1;
          if (!k) return head;
          else { i = 0; ahead = head; }
        }
      }
      for (; ahead->next; ahead = ahead->next, beyond = beyond->next);
      ahead->next = head;
      head = beyond->next;
      beyond->next = nullptr;
      return head;
    }
};

void test(ListNode* head, int k)
{
  Solution s;

  cout << "[";
  for (ListNode* h = s.rotateRight(head, k); h; h = h->next) cout << h->val << ",";
  cout << "]" << endl;
}

int main()
{
  ListNode* list1 = new ListNode(1);
  list1->next = new ListNode(2);
  list1->next->next = new ListNode(3);
  list1->next->next->next = new ListNode(4);
  list1->next->next->next->next = new ListNode(5);
  cout << "head = [1,2,3,4,5], k = 2 => [4,5,1,2,3]: ";
  test(list1, 2);

  ListNode* list2 = new ListNode(0);
  list2->next = new ListNode(1);
  list2->next->next = new ListNode(2);
  cout << "head = [0,1,2], k = 4 => [2,0,1]: ";
  test(list2, 4);

  ListNode* list3 = new ListNode(0);
  list3->next = new ListNode(1);
  list3->next->next = new ListNode(2);
  cout << "head = [0,1,2], k = 0 => [0,1,2]: ";
  test(list3, 0);

  cout << "head = [0,1,2], k = 2000000000 => [1,2,0]: ";
  test(list3, 2000000000);

  ListNode* list4 = nullptr;
  cout << "head = [], k = 0 => []: ";
  test(list4, 0);

  cout << "head = [], k = 5 => []: ";
  test(list4, 5);

  ListNode* list5 = new ListNode(1);
  cout << "head = [1], k = 1 => [1]: ";
  test(list5, 1);

  ListNode* list6 = new ListNode(1);
  list6->next = new ListNode(2);
  cout << "head = [1,2], k = 2 => [1,2]: ";
  test(list6, 2);
/*
  ListNode* list7 = new ListNode(1);
  list7->next = new ListNode(2);
  list7->next->next = new ListNode(3);
  list7->next->next->next = new ListNode(4);
  list7->next->next->next->next = new ListNode(5);
  cout << "head = [1,2,3,4,5], k = 10 => [1,2,3,4,5]: ";
  test(list7, 10);
*/
  ListNode* list8 = new ListNode(1);
  list8->next = new ListNode(2);
  cout << "head = [1,2], k = 4 => [1,2]: ";
  test(list8, 4);

  return 0;
}
