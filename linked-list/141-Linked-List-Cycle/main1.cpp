#include <algorithm>
#include <cassert>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head) return false;
        for (ListNode* slow = head, *fast = head->next; fast and fast->next; slow = slow->next, fast = fast->next->next) if (fast == slow) return true;
        return false;   
    }
};

int main()
{
    Solution s;
	ListNode head11(2);
	ListNode head13(-4); head13.next = &head11;
	ListNode head12(0); head12.next = &head13;
    head11.next = &head12;
	ListNode head10(3); head10.next = &head11;
	assert(s.hasCycle(&head10));

	ListNode head21(2);
	ListNode head20(1);
    head20.next = &head21; 
    head21.next = &head20; 
	assert(s.hasCycle(&head20));

	ListNode head30(1);
	assert(!s.hasCycle(&head30));
    return 0;
}
