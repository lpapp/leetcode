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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      ListNode* ahead = head, *beyond = head, *prev = nullptr;
      for (int i = 0; i < n and ahead; ++i, ahead = ahead->next);
      if (!ahead) return head->next;
      for (; ahead; ahead = ahead->next, prev = beyond, beyond = beyond->next);
      prev->next = beyond->next;
      return head;
    }
};

void test(ListNode* head, int n)
{
  Solution s;

  cout << "[";
  for (ListNode* h = s.removeNthFromEnd(head, n); h; h = h->next) cout << h->val << ",";
  cout << "]" << endl;
  
}

int main()
{
  ListNode* head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  cout << "head = [1,2,3,4,5], n = 2 => [1,2,3,5]: ";
  test(head, 2);

  ListNode* head2 = new ListNode(1);
  cout << "head = [1], n = 1 => []: ";
  test(head2, 1);

  ListNode* head3 = new ListNode(1);
  head3->next = new ListNode(2);
  cout << "head = [1,2], n = 1 => [1]: ";
  test(head3, 1);

  ListNode* head4 = new ListNode(1);
  head4->next = new ListNode(2);
  cout << "head = [1,2], n = 2 => [2]: ";
  test(head4, 2);

  ListNode* head5 = new ListNode(1);
  head5->next = new ListNode(2);
  head5->next->next = new ListNode(3);
  head5->next->next->next = new ListNode(4);
  head5->next->next->next->next = new ListNode(5);
  cout << "head = [1,2,3,4,5], n = 1 => [1,2,3,4]: ";
  test(head5, 1);

  return 0;
}
