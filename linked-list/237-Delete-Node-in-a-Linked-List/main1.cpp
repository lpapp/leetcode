#include <cassert>
#include <stddef.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        if (!node || !node->next) return;
        node->val = node->next->val;
        node->next = node->next->next;
    }
};

int main()
{

  Solution s;
  ListNode node1(9);
  ListNode node2(1); node2.next = &node1;
  ListNode node3(5); node3.next = &node2;
  ListNode node4(4); node4.next = &node3;
  s.deleteNode(&node3);

  ListNode node10(9);
  ListNode node20(1); node20.next = &node10;
  ListNode node30(5); node30.next = &node20;
  ListNode node40(4); node40.next = &node30;
  s.deleteNode(&node20);
  return 0;
}
