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
  ListNode* removeElements(ListNode* head, int val) {
    for (ListNode* node = head; node and node->next;) {
      if (node->next->val == val) node->next = node->next->next;
      else node = node->next;
    }
    if (head and head->val == val) head = head->next;
    return head;
  }
};

void test(ListNode* head, int val)
{
  Solution s;

  cout << "[";
  for (ListNode* h = s.removeElements(head, val); h; h = h->next) cout << h->val << ",";
  cout << "]" << endl;
}

int main()
{
  ListNode* head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(6);
  head->next->next->next = new ListNode(3);
  head->next->next->next->next = new ListNode(4);
  head->next->next->next->next->next = new ListNode(5);
  head->next->next->next->next->next->next = new ListNode(6);
  cout << "[1,2,6,3,4,5,6] | 6 => [1,2,3,4,5]: ";
  test(head, 6);

  ListNode* head2 = nullptr;
  cout << "[] | 1 => []: ";
  test(head2, 1);

  ListNode* head3 = new ListNode(7);
  head3->next = new ListNode(7);
  head3->next->next = new ListNode(7);
  head3->next->next->next = new ListNode(7);
  cout << "[7,7,7,7] | 7 => []: ";
  test(head3, 7);

  ListNode* head4 = new ListNode(50);
  head4->next = new ListNode(49);
  cout << "[50, 49] | 0 => [50,49]: ";
  test(head4, 0);

  ListNode* head5 = new ListNode(50);
  head5->next = new ListNode(49);
  cout << "[50, 49] | 50 => [49]: ";
  test(head5, 50);

  ListNode* head6 = new ListNode(50);
  head6->next = new ListNode(50);
  head6->next->next = new ListNode(49);
  cout << "[50, 50, 49] | 50 => [49]: ";
  test(head6, 50);

  ListNode* head7 = new ListNode(50);
  head7->next = new ListNode(49);
  head7->next->next = new ListNode(49);
  cout << "[50, 49, 49] | 49 => [50]: ";
  test(head7, 49);

  return 0;
}
