#include <cassert>
#include <cstdlib>

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

int main()
{

	Solution s;
	Node head14(1);
	Node head13(10); head13.next = &head14;
	Node head12(11); head12.next = &head13;
	Node head11(13); head11.next = &head12;
	Node head10(7); head10.next = &head11;
	head10.random = nullptr;
	head11.random = &head10;
	head12.random = &head14;
	head13.random = &head12;
	head14.random = &head10;
	Node* res1 = s.copyRandomList(&head10);
	assert(res1->val == 7);
	assert(res1->next->val == 13);
	assert(res1->next->next->val == 11);
	assert(res1->next->next->next->val == 10);
	assert(res1->next->next->next->next->val == 1);
    assert(!res1->random);
    assert(res1->next->random->val == 7);
    assert(res1->next->next->random->val == 1);
    assert(res1->next->next->next->random->val == 11);
    assert(res1->next->next->next->next->random->val == 7);

	Node head21(2);
	Node head20(1); head20.next = &head21;
	head20.random = &head21;
	head21.random = &head21;
	Node* res2 = s.copyRandomList(&head20);
	assert(res2->val == 1);
	assert(res2->next->val == 2);
    assert(res2->random->val == 2);
    assert(res2->next->random->val == 2);

	Node head32(3);
	Node head31(3); head31.next = &head32;
	Node head30(3); head30.next = &head31;
	head30.random = nullptr;
	head31.random = &head30;
	head32.random = nullptr;
	Node* res3 = s.copyRandomList(&head30);
	assert(res3->val == 3);
	assert(res3->next->val == 3);
	assert(res3->next->next->val == 3);
    assert(!res3->random);
    assert(res3->next->random->val == 3);
    assert(!res3->next->next->random);
	return 0;
}
