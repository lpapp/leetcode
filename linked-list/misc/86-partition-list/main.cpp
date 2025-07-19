struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* beforeStart = nullptr;
        ListNode* beforeEnd = nullptr;
        ListNode* afterStart = nullptr;
        ListNode* afterEnd = nullptr;

        // Partition list
        while (head) {
            ListNode* next = head->next;
            head->next = nullptr;
            if (head->val < x) {
                // Insert the node into the end of the before list.
                if (!beforeStart) { beforeStart = head; beforeEnd = beforeStart; }
                else { beforeEnd->next = head; beforeEnd = head; }
            } else {
                // Insert the node into the end of the after list.
                if (!afterStart) { afterStart = head; afterEnd = afterStart; }
                else { afterEnd->next = head; afterEnd = head; }
            }
            head = next;
        }

        if (!beforeStart) return afterStart;

        // Merge the before list and after list
        beforeEnd->next = afterStart;
        return beforeStart;
    }
};

int main()
{
    Solution s;
    ListNode node(5);
    s.partition(&node, 3);
    return 0;
}
