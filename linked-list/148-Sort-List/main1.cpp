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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* slow, *fast;
        for (slow = head, fast = head->next; fast && fast->next; slow = slow->next, fast = fast->next->next);
        ListNode* first = head, *second = slow->next;
        slow->next = nullptr;
        first = sortList(first);
        second = sortList(second);
        ListNode* dummy, *tail;
		for (dummy = new ListNode(0), tail = dummy; first && second; tail = tail->next) {
            if (first->val <= second->val) { tail->next = first; first = first->next; }
			else { tail->next = second; second = second->next; }
        }
        tail->next = first ? first : second;
        ListNode* sorted = dummy->next;
        delete dummy;
        return sorted;
    }
};

int main()
{

	Solution s;
	ListNode node1(3);
	ListNode node2(1); node2.next = &node1;
	ListNode node3(2); node3.next = &node2;
	ListNode node4(4); node4.next = &node3;
	ListNode* res = s.sortList(&node4);
	assert(res->val == 1);
	assert(res->next->val == 2);
	assert(res->next->next->val == 3);
	assert(res->next->next->next->val == 4);
	assert(!res->next->next->next->next);
	
	ListNode node10(0);
	ListNode node20(4); node20.next = &node10;
	ListNode node30(3); node30.next = &node20;
	ListNode node40(5); node40.next = &node30;
	ListNode node50(-1); node50.next = &node40;
	res = s.sortList(&node50);
	assert(res->val == -1);
	assert(res->next->val == 0);
	assert(res->next->next->val == 3);
	assert(res->next->next->next->val == 4);
	assert(res->next->next->next->next->val == 5);
	assert(!res->next->next->next->next->next);
	return 0;
}
