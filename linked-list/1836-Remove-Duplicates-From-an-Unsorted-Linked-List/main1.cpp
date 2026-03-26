#include <iostream>
#include <unordered_map>

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
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        unordered_map<int, int> hash;
        for (ListNode* node = head; node; node = node->next) ++hash[node->val];
        ListNode* preHead = new ListNode(0, head);
        for (ListNode* previous = preHead, *current = head; current; current = current->next) {
            if (hash[current->val] > 1) previous->next = current->next;
            else previous = current;
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
    ListNode node16(2, &node17);
    ListNode node15(4, &node16);
    ListNode node14(3, &node15);
    ListNode node13(2, &node14);
    ListNode node12(1, &node13);
    ListNode node11(3, &node12);
    printListNode(s.deleteDuplicatesUnsorted(&node11));

    ListNode node25(4);
    ListNode node24(2, &node25);
    ListNode node23(3, &node24);
    ListNode node22(2, &node23);
    ListNode node21(1, &node22);
    printListNode(s.deleteDuplicatesUnsorted(&node21));
	return 0;
}
