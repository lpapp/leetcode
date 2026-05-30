#include <cassert>
#include <queue>
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
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto compare = [](ListNode* a, ListNode* b) { return a->val > b->val; };
		priority_queue<ListNode*, vector<ListNode*>, decltype(compare)> minHeap(compare);
		for (ListNode* head : lists) { if (head) minHeap.push(head); }
        ListNode* dummy = new ListNode(0);
        for (ListNode* current = dummy; !minHeap.empty(); current = current->next) {
            ListNode* node = minHeap.top(); minHeap.pop();
            if (node->next) minHeap.push(node->next);
            current->next = node;
        }
        return dummy->next;
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
