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
    ListNode* reverseList(ListNode* head) {
    	ListNode* prev = nullptr;
    	while (head) { ListNode* next = head->next; head->next = prev; prev = head; head = next; }
    	return prev;       
    }
};

int main()
{

	Solution s;
	ListNode head14(5);
	ListNode head13(4, &head14);
	ListNode head12(3, &head13);
	ListNode head11(2, &head12);
	ListNode head10(1, &head11);
	ListNode* res1 = s.reverseList(&head10);
	assert(res1->val == 5);
	assert(res1->next->val == 4);
	assert(res1->next->next->val == 3);
	assert(res1->next->next->next->val == 2);
	assert(res1->next->next->next->next->val == 1);
	assert(!res1->next->next->next->next->next);
	ListNode head21(2);
	ListNode head20(1, &head21);
	ListNode* res2 = s.reverseList(&head20);
	assert(res2->val == 2);
	assert(res2->next->val == 1);
	assert(!res2->next->next);
	ListNode* head30 = nullptr;
	ListNode* res3 = s.reverseList(head30);
	assert(!res3);
	return 0;
}
