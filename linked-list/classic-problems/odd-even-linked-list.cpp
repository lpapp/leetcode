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
    // -> 1, 2, 3, 4, 5 -> write_node: 1, read_node: 2
    // -> 1, 3, 2, 4, 5 -> write_node: 3, read_node: 4
    ListNode* oddEvenList(ListNode* head) {
      if (!head) return head;
      for (ListNode* write_node = head, *read_node = head->next; read_node and read_node->next; write_node = write_node->next, read_node = read_node->next) {
        ListNode* odd_node = read_node->next;
        read_node->next = read_node->next->next;
        odd_node->next = write_node->next;
        write_node->next = odd_node;
      }
      return head;
    }
};

void test(ListNode* head)
{
  Solution s;

  cout << "[";
  for (ListNode* h = s.oddEvenList(head); h; h = h->next) cout << h->val << ",";
  cout << "]" << endl;
}

int main()
{
  ListNode* head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  cout << "[1,2,3,4,5] => [1,3,5,2,4]: ";
  test(head);

  ListNode* head2 = new ListNode(2);
  head2->next = new ListNode(1);
  head2->next->next = new ListNode(3);
  head2->next->next->next = new ListNode(5);
  head2->next->next->next->next = new ListNode(6);
  head2->next->next->next->next->next = new ListNode(4);
  head2->next->next->next->next->next->next = new ListNode(7);
  cout << "[2,1,3,5,6,4,7] => [2,3,6,7,1,5,4]: ";
  test(head2);


  ListNode* head3 = nullptr;
  cout << "[] => []: ";
  test(head3);

  ListNode* head4 = new ListNode(1);
  head4->next = new ListNode(2);
  head4->next->next = new ListNode(3);
  head4->next->next->next = new ListNode(1000000);
  cout << "[1,2,3,1000000] => [1,3,2,1000000]: ";
  test(head4);

  ListNode* head5 = new ListNode(-1000000);
  cout << "[-1000000] => [-1000000]: ";
  test(head5);

  return 0;
}
