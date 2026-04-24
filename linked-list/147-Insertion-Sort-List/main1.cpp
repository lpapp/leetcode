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
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* dummy = new ListNode(numeric_limits<int>::min());
        for (ListNode* current = head; current;) {
            ListNode* next = current->next;
            ListNode* it = dummy;
            for (; it->next && it->next->val < current->val; it = it->next);
            current->next = it->next;
            it->next = current;
            current = next;
        }
        return dummy->next;
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
    ListNode node13(2, &node14);
    ListNode node12(1, &node13);
    ListNode node11(3, &node12);
    printListNode(s.insertionSortList(&node11));

    ListNode node25(-1);
    ListNode node24(5, &node25);
    ListNode node23(3, &node24);
    ListNode node22(4, &node23);
    ListNode node21(0, &node22);
    printListNode(s.insertionSortList(&node21));
	return 0;
}
