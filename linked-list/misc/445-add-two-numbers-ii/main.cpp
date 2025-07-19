#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct PartialSum
{
    ListNode* sum{nullptr};
    int carry{0};
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        const size_t l1Size = length(l1);
        const size_t l2Size = length(l2);

        // Pad the shorter list with zeroes.
        if (l1Size < l2Size) l1 = padList(l1, l2Size - l1Size);
        else l2 = padList(l2, l1Size - l2Size);

        // Add lists
        PartialSum sum = addListHelper(l1, l2);

	// If there was a carry value left over, insert this at the front of
        // the list. Otherwise, just return the linked list.
        if (!sum.carry) return sum.sum;
        
        return insertBefore(sum.sum, sum.carry);
    }

    PartialSum addListHelper(ListNode* l1, ListNode* l2) {
        if (!l1 && !l2) { PartialSum sum; return sum; }

        // Add smaller digits recursively.
        PartialSum sum = addListHelper(l1->next, l2->next);

        // Add carry to the current data.
        int val = sum.carry + l1->val + l2->val;

        // Insert the sum of the current digits.
        ListNode* full_result = insertBefore(sum.sum, val % 10);

        // Return the sum so far, and the carry value.
        sum.sum = full_result;
        sum.carry = val / 10;
        return sum;
    }

    // Pad the list with zeroes
    ListNode* padList(ListNode* l, size_t padding) {
        ListNode* head = l;
        for (size_t i = 0; i < padding; ++i) head = insertBefore(head, 0);
        return head;
    }

    // Helper function to insert the node in the front of a linked list.
    ListNode* insertBefore(ListNode* list, int data) {
        ListNode* node = new ListNode(data);
        if (list) node->next = list;
        return node;
    }

    size_t length(ListNode* head) 
    { 
        size_t count = 0; 
        for (ListNode* current = head; current; ++count, current = current->next);
        return count; 
    } 
};

int main()
{
    Solution s;
    ListNode node1(3);
    ListNode node2(5);
    s.addTwoNumbers(&node1, &node2);
    return 0;
}
