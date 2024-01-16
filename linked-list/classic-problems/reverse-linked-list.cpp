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
  ListNode* reverseList_iterative(ListNode* head) {
    for (ListNode* node = head; node and node->next;) {
      ListNode* new_head = node->next;
      node->next = node->next->next;
      new_head->next = head;
      head = new_head;
    }
    return head;
  }

/*
  -> 1-2-3-4-5 -> 1->nullptr
  -> 2-3-4-5   -> 2->1
  -> 3-4-5     -> 3->2
  ...
 */
  ListNode* reverseList_iterative_two(ListNode* head) {
    ListNode* new_head, *next;
    for (new_head = nullptr; head; head = next) {
      next = head->next;
      head->next = new_head;
      new_head = head;
    }
    return new_head;
  }

/*
  1 2 3 4 5 ->
  head: 1 ->
    head: 2 ->
      head: 3 ->
        head: 4 ->
          head: 5 (next null) -> return 5
        -> 1 2 3 4 5 -> 4
        -> 1 2 3 4 -> null -> return 5
      -> 1 2 3 4 -> 3
      -> 1 2 3 -> null -> return 5
    -> 1 2 3 -> 2
    -> 1 2 -> null -> return 5
  -> 1 2 -> 1
  -> 1 -> null -> return 5
*/
  ListNode* reverseList_recursive(ListNode* head) {
    if (!head or !head->next) return head;
    ListNode* new_head = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return new_head;
  }

/*
  1 2 3 4 5 ->                                                            
  head: 1, new_head: nullptr => (1 -> nullptr)                            
    -> head: 2, new_head: 1 => (2 -> 1)                                   
      -> head: 3, new_head: 2 => (3 -> 2)                                 
        -> head: 4, new_head: 3 => (4 -> 3)                               
          -> head: 5, new_head: 4 => (5 -> 4)                             
            -> head: nullptr, new_head: 5 => return 5
*/
  ListNode* reverseList_rec(ListNode* head, ListNode* prev)
  {
    if (!head) return prev;
    ListNode* next = head->next;
    head->next = prev;
    return reverseList_rec(next, head);
  }

  ListNode* reverseList(ListNode* head) {
    return reverseList_rec(head, nullptr);
  }
};

void test(ListNode* head)
{
  Solution s;

  cout << "[";
  for (ListNode* h = s.reverseList_iterative(head); h; h = h->next) cout << h->val << ",";
  cout << "]" << endl;
}

int main()
{
  ListNode* head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  cout << "[1,2,3,4,5] => [5,4,3,2,1]: ";
  test(head);

  ListNode* head2 = new ListNode(1);
  head2->next = new ListNode(2);
  cout << "[1,2] => [2,1]: ";
  test(head2);

  ListNode* head3 = nullptr;
  cout << "[] => []: ";
  test(head3);

  return 0;
}
