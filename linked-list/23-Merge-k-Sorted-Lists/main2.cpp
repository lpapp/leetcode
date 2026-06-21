#include <cassert>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    ListNode* merge2(ListNode* a, ListNode* b) {
        ListNode dummy, *tail;
        for (tail = &dummy; a && b; tail = tail->next) { if (a->val <= b->val) { tail->next = a; a = a->next; } else { tail->next = b; b = b->next; } }
        tail->next = a ? a : b;
        return dummy.next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        const int n = lists.size();
        if (!n) return nullptr;
        for (int step = 1; step < n; step *= 2) for (int i = 0; i + step < n; i += step * 2) lists[i] = merge2(lists[i], lists[i + step]);
        return lists[0];
    }
};

int main()
{
    Solution s;
    ListNode node12(5);
    ListNode node13(4); node13.next = &node12;
    ListNode node14(1); node14.next = &node13;
    ListNode node22(4);
    ListNode node23(3); node23.next = &node22;
    ListNode node24(1); node24.next = &node23;
    ListNode node33(6);
    ListNode node34(2); node34.next = &node33;
    vector<ListNode*> lists1 = {&node34, &node24, &node14};
    ListNode* res1 = s.mergeKLists(lists1);
    assert(res1->val == 1);
    assert(res1->next->val == 1);
    assert(res1->next->next->val == 2);
    assert(res1->next->next->next->val == 3);
    assert(res1->next->next->next->next->val == 4);
    assert(res1->next->next->next->next->next->val == 4);
    assert(res1->next->next->next->next->next->next->val == 5);
    assert(res1->next->next->next->next->next->next->next->val == 6);
    vector<ListNode*> lists2 = {};
    ListNode* res2 = s.mergeKLists(lists2);
    assert(!res2);
    vector<ListNode*> lists3 = {nullptr};
    ListNode* res3 = s.mergeKLists(lists3);
    assert(!res3);
    return 0;
}
