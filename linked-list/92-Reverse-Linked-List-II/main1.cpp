#include <cassert>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head->next || left == right) return head;
        ListNode* dummyNode = new ListNode(0, head), * beforeReversal = dummyNode;
        for (int i = 0; i < left - 1; ++i) beforeReversal = beforeReversal->next;
        ListNode* nodeBeforeReversal = beforeReversal, *firstReversalNode = beforeReversal->next;
        ListNode* current = firstReversalNode, *prev = beforeReversal;
        for (int i = 0; i < right - left + 1; ++i) {
            ListNode* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        nodeBeforeReversal->next = prev;
        firstReversalNode->next = current;
        return dummyNode->next;       
    }
};

int main()
{
	Solution s;
	ListNode* list15 = new ListNode(5);
	ListNode* list14 = new ListNode(4, list15);
	ListNode* list13 = new ListNode(3, list14);
	ListNode* list12 = new ListNode(2, list13);
	ListNode* list11 = new ListNode(1, list12);
	assert(s.reverseBetween(list11, 2, 4) == list11);
	ListNode* list21 = new ListNode(5);
	assert(s.reverseBetween(list21, 1, 1) == list21);
	return 0;
}
