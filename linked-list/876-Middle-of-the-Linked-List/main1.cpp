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
    ListNode* middleNode(ListNode* head) {
        ListNode* result = head;
        for (ListNode* fast = head; fast && fast->next; result = result->next, fast = fast->next->next);
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
    ListNode node15(5);
    ListNode node14(4, &node15);
    ListNode node13(3, &node14);
    ListNode node12(2, &node13);
    ListNode node11(1, &node12);
    printListNode(s.middleNode(&node11));

    ListNode node26(6);
    ListNode node25(5, &node26);
    ListNode node24(4, &node25);
    ListNode node23(3, &node24);
    ListNode node22(2, &node23);
    ListNode node21(1, &node22);
    printListNode(s.middleNode(&node21));
	return 0;
}
