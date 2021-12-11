#include <iostream>

using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
      for (Node* node = head, *next, *child_node; node; node = next) {
        next = node->next;
        if (node->child) {
          node->next = node->child;
          node->child->prev = node;
          for (child_node = node->child; child_node->next; child_node = child_node->next);
          child_node->next = next;
          next->prev = child_node;
        }
      }
      return head;
    }
};

void test(Node* head)
{
  Solution s;

  cout << "[";
  for (Node* h = s.flatten(head); h; h = h->next) cout << h->val << ",";
  cout << "]" << endl;
}

int main()
{
  Node* child_list2 = new Node;
  child_list2->val = 11;
  child_list2->prev = nullptr;
  child_list2->child = nullptr;
  child_list2->next = new Node;

  child_list2->next->val = 12;
  child_list2->next->prev = child_list2;
  child_list2->next->child = nullptr;
  child_list2->next->next = nullptr;

  Node* child_list1 = new Node;
  child_list1->val = 7;
  child_list1->prev = nullptr;
  child_list1->child = nullptr;
  child_list1->next = new Node;

  child_list1->next->val = 8;
  child_list1->next->prev = child_list1;
  child_list1->next->child = child_list2;
  child_list1->next->next = new Node;

  child_list1->next->next->val = 9;
  child_list1->next->next->prev = child_list1->next;
  child_list1->next->next->child = nullptr;
  child_list1->next->next->next = new Node;

  child_list1->next->next->next->val = 10;
  child_list1->next->next->next->prev = child_list1->next->next;
  child_list1->next->next->next->child = nullptr;
  child_list1->next->next->next->next = nullptr;

  Node* list1 = new Node;
  list1->val = 1;
  list1->prev = nullptr;
  list1->child = nullptr;
  list1->next = new Node;

  list1->next->val = 2;
  list1->next->prev = list1;
  list1->next->child = nullptr;
  list1->next->next = new Node;

  list1->next->next->val = 3;
  list1->next->next->prev = list1->next;
  list1->next->next->child = child_list1;
  list1->next->next->next = new Node;

  list1->next->next->next->val = 4;
  list1->next->next->next->prev = list1->next->next;
  list1->next->next->next->child = nullptr;
  list1->next->next->next->next = new Node;

  list1->next->next->next->next->val = 5;
  list1->next->next->next->next->prev = list1->next->next->next;
  list1->next->next->next->next->child = nullptr;
  list1->next->next->next->next->next = new Node;

  list1->next->next->next->next->next->val = 6;
  list1->next->next->next->next->next->prev = list1->next->next->next->next;
  list1->next->next->next->next->next->child = nullptr;
  list1->next->next->next->next->next->next = nullptr;

  cout << "head = [1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12] => [1,2,3,7,8,11,12,9,10,4,5,6]: ";
  test(list1);

  return 0;
}
