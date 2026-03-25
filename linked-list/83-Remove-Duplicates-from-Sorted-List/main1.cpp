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
        for (ListNode* node = head; node && node->next;) {
            if (node->val == node->next->val) node->next = node->next->next;
            else node = node->next;
        }
        return head;
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
    ListNode node13(2);
    ListNode node12(1, &node13);
    ListNode node11(1, &node12);
    printListNode(s.deleteDuplicates(&node11));

    ListNode node25(3);
    ListNode node24(3, &node25);
    ListNode node23(2, &node24);
    ListNode node22(1, &node23);
    ListNode node21(1, &node22);
    printListNode(s.deleteDuplicates(&node21));
	return 0;
}
