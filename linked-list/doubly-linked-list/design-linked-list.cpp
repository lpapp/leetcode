#include <iostream>

using namespace std;

struct Node
{
  int value;
  Node* prev, *next;
  Node(int x, Node* prev = nullptr, Node* next = nullptr) : value(x), prev(prev), next(next) {}
};

class MyLinkedList {
public:
    MyLinkedList() {
    }

    int get(int index) {
      Node* node = head;
      for (int i = 0; i < index and node; ++i, node = node->next);
      return node ? node->value : -1;
    }

    void addAtHead(int val) {
      Node* node = new Node(val, nullptr, head);
      if (head) head->prev = node;
      head = node;
    }

    void addAtTail(int val) {
      Node* new_node = new Node(val);
      if (!head) head = new_node;
      else {
        Node* node;
        for (node = head; node->next; node = node->next);
        node->next = new_node;
        new_node->prev = node;
      }
    }

    void addAtIndex(int index, int val) {
      Node* new_node = new Node(val);
      if (!index) { new_node->next = head; if (head) head->prev = new_node; head = new_node; return; }

      Node* node = head;
      for (int i = 1 ; i < index and node; ++i, node = node->next);
      if (!node) return;

      new_node->next = node->next;
      new_node->prev = node;
      if (node->next) node->next->prev = new_node;
      node->next = new_node;
    }

    void deleteAtIndex(int index) {
      if (!index and head) { head = head->next; if (head) head->prev = nullptr; return; }

      Node* node = head;
      for (int i = 1; i < index and node; ++i, node = node->next);
      if (node and node->next) { node->next = node->next->next; if (node->next) node->next->prev = node; }
    }

private:
  Node *head = nullptr;
};

void test()
{
  MyLinkedList myLinkedList;
  cout << myLinkedList.get(0) << endl; // return -1
  myLinkedList.addAtIndex(1, 1);       // linked list remains empty
  cout << myLinkedList.get(0) << endl; // return -1
  myLinkedList.addAtHead(1);
  myLinkedList.addAtTail(3);
  myLinkedList.addAtIndex(1, 2);       // linked list becomes 1->2->3
  cout << myLinkedList.get(1) << endl; // return 2
  myLinkedList.deleteAtIndex(1);       // now the linked list is 1->3
  cout << myLinkedList.get(1) << endl; // return 3
  myLinkedList.addAtIndex(2, 4);       // linked list becomes 1->3->4
  myLinkedList.addAtIndex(4, 5);       // linked list becomes 1->3->4
  cout << myLinkedList.get(2) << endl; // return 4
  cout << myLinkedList.get(3) << endl; // return -1
  myLinkedList.deleteAtIndex(3);
  cout << "==========================" << endl;
}

void test2()
{
  MyLinkedList myLinkedList;
  myLinkedList.addAtHead(2);           // 2
  myLinkedList.deleteAtIndex(1);       // 2
  myLinkedList.addAtHead(2);           // 2->2
  myLinkedList.addAtHead(7);           // 7->2->2
  myLinkedList.addAtHead(3);           // 3->7->2->2
  myLinkedList.addAtHead(2);           // 2->3->7->2->2
  myLinkedList.addAtHead(5);           // 5->2->3->7->2->2
  myLinkedList.addAtTail(5);           // 5->2->3->7->2->2->5
  cout << myLinkedList.get(5) << endl; // return 2
  myLinkedList.deleteAtIndex(6);       // 5->2->3->7->2->2
  myLinkedList.deleteAtIndex(4);       // 5->2->3->7->2
  cout << "==========================" << endl;
}

void test3()
{
  MyLinkedList myLinkedList;
  myLinkedList.addAtHead(4);           // 4
  cout << myLinkedList.get(1) << endl; // return -1
  myLinkedList.addAtHead(1);           // 1->4
  myLinkedList.addAtHead(5);           // 5->1->4
  myLinkedList.deleteAtIndex(3);       // 5->1->4
  myLinkedList.addAtHead(7);           // 7->5->1->4
  cout << myLinkedList.get(3) << endl; // return 4
  cout << myLinkedList.get(3) << endl; // return 4
  cout << myLinkedList.get(3) << endl; // return 4
  myLinkedList.addAtHead(1);           // 1->7->5->1->4
  cout << myLinkedList.get(4) << endl; // return 4
  myLinkedList.deleteAtIndex(4);       // 1->7->5->1
  cout << myLinkedList.get(4) << endl; // return -1
  cout << "==========================" << endl;
}

void test4()
{
  MyLinkedList myLinkedList;
  myLinkedList.addAtHead(1);           // 1
  myLinkedList.deleteAtIndex(0);       // empty
  cout << "==========================" << endl;
}

void test5()
{
  MyLinkedList myLinkedList;
  myLinkedList.addAtHead(1);           // 1
  myLinkedList.addAtTail(3);           // 1->3
  myLinkedList.addAtIndex(1, 2);       // 1->2->3
  cout << myLinkedList.get(1) << endl; // return 2
  myLinkedList.deleteAtIndex(1);       // 1->3
  cout << myLinkedList.get(1) << endl; // return 3
  cout << myLinkedList.get(3) << endl; // return -1
  myLinkedList.deleteAtIndex(3);       // 1->3
  myLinkedList.deleteAtIndex(0);       // 3
  cout << myLinkedList.get(0) << endl; // return 3
  myLinkedList.deleteAtIndex(0);       // empty
  cout << myLinkedList.get(0) << endl; // return -1
  cout << "==========================" << endl;
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

int main()
{
  test();
  test2();
  test3();
  test4();
  test5();
  return 0;
}
