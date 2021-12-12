#include <iostream>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
      for (Node* node = head, *next; node; node = next) {
        next = node->next;
        node->next = new Node(node->val);
        node->next->next = next;
      }

      for (Node* node = head; node; node = node->next->next) if (node->random) node->next->random = node->random->next;

      Node* node, *new_head;
      for (node = nullptr, new_head = node; head; head->next = head->next->next, head = head->next) {
        if (node) { node->next = head->next; node = node->next; } 
        else { node = head->next; new_head = node; }
      }
      return new_head;
    }
};

void test(Node* head)
{
  Solution s;

  cout << "[";
  for (Node* h = s.copyRandomList(head); h; h = h->next) cout << "[" << h->val << "," << (h->random ? to_string(h->random->val) : "null") << "],";
  cout << "]" << endl;
}

int main()
{
  Node* list1 = new Node(7);
  list1->next = new Node(13);
  list1->next->next = new Node(11);
  list1->next->next->next = new Node(10);
  list1->next->next->next->next = new Node(1);

  list1->next->random = list1;
  list1->next->next->random = list1->next->next->next->next;
  list1->next->next->next->random = list1->next->next;
  list1->next->next->next->next->random = list1;

  cout << "head = [[7,null],[13,0],[11,4],[10,2],[1,0]] => [[7,null],[13,0],[11,4],[10,2],[1,0]]: ";
  test(list1);


  Node* list2 = new Node(1);
  list2->next = new Node(2);

  list2->random = list2->next;
  list2->next->random = list2->next;

  cout << "head = [[1,1],[2,1]] => [[1,1],[2,1]]: ";
  test(list2);


  Node* list3 = new Node(3);
  list3->next = new Node(3);
  list3->next->next = new Node(3);

  list3->next->random = list3;

  cout << "[[3,null],[3,0],[3,null]] => [[3,null],[3,0],[3,null]]: ";
  test(list3);


  Node* list4 = nullptr;
  cout << "head = [] => []: ";
  test(list4);

  return 0;
}
