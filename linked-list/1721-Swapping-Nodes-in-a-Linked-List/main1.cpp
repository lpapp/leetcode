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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* ahead = head;
        while (--k) ahead = ahead->next;
        ListNode* first = ahead;
        ListNode* node = head;
        for (; ahead->next; ahead = ahead->next, node = node->next);
        ListNode* second = node;
        swap(first->val, second->val);
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
    ListNode node15(5);
    ListNode node14(4, &node15);
    ListNode node13(3, &node14);
    ListNode node12(2, &node13);
    ListNode node11(1, &node12);
    printListNode(s.swapNodes(&node11, 2));

    ListNode node210(5);
    ListNode node209(9, &node210);
    ListNode node208(0, &node209);
    ListNode node207(3, &node208);
    ListNode node206(8, &node207);
    ListNode node205(7, &node206);
    ListNode node204(6, &node205);
    ListNode node203(6, &node204);
    ListNode node202(9, &node203);
    ListNode node201(7, &node202);
    printListNode(s.swapNodes(&node201, 5));
	return 0;
}
