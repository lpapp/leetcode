#include <iostream>
#include <utility>

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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* preHead = new ListNode(0, head), *slow = preHead;
        for (ListNode* fast = head; fast && fast->next; slow = slow->next, fast = fast->next->next);
        slow->next = slow->next->next;
        return preHead->next;      
    }
};

void printListNode(ListNode* head) {
    cout << "[";
    for (; head; head = head->next) cout << head->val << ",";
    cout << "]" << endl;
}

int main()
{
	Solution s;
    ListNode node107(6);
    ListNode node106(2, &node107);
    ListNode node105(1, &node106);
    ListNode node104(7, &node105);
    ListNode node103(4, &node104);
    ListNode node102(3, &node103);
    ListNode node101(1, &node102);
    printListNode(s.deleteMiddle(&node101));

    ListNode node204(4);
    ListNode node203(3, &node204);
    ListNode node202(2, &node203);
    ListNode node201(1, &node202);
    printListNode(s.deleteMiddle(&node201));
	return 0;
}
