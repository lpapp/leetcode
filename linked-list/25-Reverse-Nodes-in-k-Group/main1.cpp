#include <cassert>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    ListNode* reverseList(ListNode* head) {
        ListNode* dummy = new ListNode(), *current = head;
        while (current) {
            ListNode* next = current->next;
            current->next = dummy->next;
            dummy->next = current;
            current = next;
        }
        return dummy->next;      
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0, head), *prevReversalEnd = dummy;
        while (prevReversalEnd) {
            ListNode* current = prevReversalEnd;
            for (int i = 0; i < k; ++i) { current = current->next; if (current) return dummy->next; }
            ListNode* reversalStart = prevReversalEnd->next;
            ListNode* nextReversalStart = current->next;
            current->next = nullptr;
            prevReversalEnd->next = reverseList(reversalStart);
            reversalStart->next = nextReversalStart;
            prevReversalEnd = reversalStart;
        }
        return dummy->next;  
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
	assert(s.reverseKGroup(list11, 2) == list11);
	ListNode* list25 = new ListNode(5);
	ListNode* list24 = new ListNode(4, list25);
	ListNode* list23 = new ListNode(3, list24);
	ListNode* list22 = new ListNode(2, list23);
	ListNode* list21 = new ListNode(1, list22);
	assert(s.reverseKGroup(list21, 3) == list21);
	return 0;
}
