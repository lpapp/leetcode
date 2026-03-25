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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* preHead = new ListNode(0, head);
        for (ListNode *previous = preHead, *current = head; current; current = current->next) {
            while (current->next && current->next->val == current->val) current = current->next;
            if (previous->next == current) previous = current;
            else previous->next = current->next;
        }
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
    ListNode node17(5);
    ListNode node16(4, &node17);
    ListNode node15(4, &node16);
    ListNode node14(3, &node15);
    ListNode node13(3, &node14);
    ListNode node12(2, &node13);
    ListNode node11(1, &node12);
    printListNode(s.deleteDuplicates(&node11));

    ListNode node25(3);
    ListNode node24(2, &node25);
    ListNode node23(1, &node24);
    ListNode node22(1, &node23);
    ListNode node21(1, &node22);
    printListNode(s.deleteDuplicates(&node21));
	return 0;
}
