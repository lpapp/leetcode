#include <cassert>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        ListNode* slow = head;
        for (ListNode* fast = head; fast->next && fast->next->next; slow = slow->next, fast = fast->next->next);
        ListNode* prev = nullptr, *cur = slow->next;
        for (slow->next = nullptr; cur;) { ListNode* next = cur->next; cur->next = prev; prev = cur; cur = next; }
        for (ListNode* first = head, *second = prev; second;) { ListNode* tmp1 = first->next, *tmp2 = second->next; first->next = second; second->next = tmp1; first = tmp1; second = tmp2; }
    }
};

int main()
{
    Solution s;
    ListNode head13(4);
    ListNode head12(3, &head13);
    ListNode head11(2, &head12);
    ListNode head10(1, &head11);
    s.reorderList(&head10);
    assert(head10.val == 1);
    assert(head10.next->val == 4);
    assert(head10.next->next->val == 2);
    assert(head10.next->next->next->val == 3);
    ListNode head24(5);
    ListNode head23(4, &head24);
    ListNode head22(3, &head23);
    ListNode head21(2, &head22);
    ListNode head20(1, &head21);
    s.reorderList(&head20);
    assert(head20.val == 1);
    assert(head20.next->val == 5);
    assert(head20.next->next->val == 2);
    assert(head20.next->next->next->val == 4);
    assert(head20.next->next->next->next->val == 3);
    return 0;
}
