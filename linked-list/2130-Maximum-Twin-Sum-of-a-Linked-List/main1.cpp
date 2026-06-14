#include <algorithm>
#include <cassert>

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
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        for (ListNode* fast = head; fast && fast->next; slow = slow->next, fast = fast->next->next);
        ListNode* prev = nullptr;
        while (slow) { ListNode* next = slow->next; slow->next = prev; prev = slow; slow = next; }
        int res = 0;
        while (prev) { res = max(res, head->val + prev->val); head = head->next; prev = prev->next; }
        return res;       
    }
};

int main()
{

	Solution s;
	ListNode head13(1);
	ListNode head12(2, &head13);
	ListNode head11(4, &head12);
	ListNode head10(5, &head11);
	assert(s.pairSum(&head10) == 6);
	ListNode head23(3);
	ListNode head22(2, &head23);
	ListNode head21(2, &head22);
	ListNode head20(4, &head21);
	assert(s.pairSum(&head20) == 7);
	ListNode head31(100000);
	ListNode head30(1, &head31);
	assert(s.pairSum(&head30) == 100001);
	return 0;
}
