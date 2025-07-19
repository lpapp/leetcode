struct ListNode {
    int val;
    ListNode *next{nullptr};
    ListNode(int x) : val(x) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        if (!node || !node->next) return;
        ListNode* next = node->next;
        node->val = next->val;
        node->next = next->next;
    }
};

int main()
{

  Solution s;
  ListNode node(2);
  s.deleteNode(&node);
  return 0;
}
