#include <iostream>

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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* remaining = swapPairs(head->next->next);
        ListNode* result = head->next;
        result->next = head;
        head->next = remaining;
        return result;
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
    ListNode node14(4);
    ListNode node13(3, &node14);
    ListNode node12(2, &node13);
    ListNode node11(1, &node12);
    printListNode(s.swapPairs(&node11));

    ListNode* node21 = nullptr;
    printListNode(s.swapPairs(node21));

    ListNode node31(1);
    printListNode(s.swapPairs(&node31));

    ListNode node43(3);
    ListNode node42(2, &node43);
    ListNode node41(1, &node42);
    printListNode(s.swapPairs(&node41));
	return 0;
}
