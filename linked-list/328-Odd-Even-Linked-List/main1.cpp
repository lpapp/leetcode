#include <cassert>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
    	if (!head) return head;
    	ListNode* odd = head, *evenHead = head->next;
    	for (ListNode* even = head->next; even and even->next; odd = odd->next, even->next = odd->next, even = even->next) odd->next = even->next;
    	odd->next = evenHead;
    	return head;       
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
	s.oddEvenList(&head10);
	assert(head10.val == 1);
	assert(head10.next->val == 3);
	assert(head10.next->next->val == 5);
	assert(head10.next->next->next->val == 2);
	assert(head10.next->next->next->next->val == 4);
	assert(!head10.next->next->next->next->next);
	ListNode head26(7);
	ListNode head25(4, &head26);
	ListNode head24(6, &head25);
	ListNode head23(5, &head24);
	ListNode head22(3, &head23);
	ListNode head21(1, &head22);
	ListNode head20(2, &head21);
	s.oddEvenList(&head20);
	assert(head20.val == 2);
	assert(head20.next->val == 3);
	assert(head20.next->next->val == 6);
	assert(head20.next->next->next->val == 7);
	assert(head20.next->next->next->next->val == 1);
	assert(head20.next->next->next->next->next->val == 5);
	assert(head20.next->next->next->next->next->next->val == 4);
	assert(!head20.next->next->next->next->next->next->next);
	return 0;
}
