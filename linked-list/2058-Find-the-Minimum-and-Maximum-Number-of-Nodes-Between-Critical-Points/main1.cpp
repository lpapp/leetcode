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
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int first = -1, last = -1, minDist = INT_MAX, prev = head->val, i = 1;
        for (ListNode* cur = head->next; cur->next; prev = cur->val, cur = cur->next, ++i) {
            const int val = cur->val, next = cur->next->val;
            if ((val < prev && val < next) || (val > prev && val > next)) {
                if (last < 0) first = i;
                else minDist = min(minDist, i - last);
                last = i;
            }
        }
        return first == last ? vector<int>{-1, -1} : vector<int>{minDist, last - first};
    }
};

int main()
{
    Solution s;

    ListNode node102(3);
    ListNode node101(1, &node102);
    vector<int> res1 = {-1, -1};
    assert(s.nodesBetweenCriticalPoints(&node101) == res1);

    ListNode node207(2);
    ListNode node206(1, &node207);
    ListNode node205(5, &node206);
    ListNode node204(2, &node205);
    ListNode node203(1, &node204);
    ListNode node202(3, &node203);
    ListNode node201(5, &node202);
    vector<int> res2 = {1, 3};
    assert(s.nodesBetweenCriticalPoints(&node201) == res2);

    ListNode node309(7);
    ListNode node308(2, &node309);
    ListNode node307(2, &node308);
    ListNode node306(2, &node307);
    ListNode node305(3, &node306);
    ListNode node304(2, &node305);
    ListNode node303(2, &node304);
    ListNode node302(3, &node303);
    ListNode node301(1, &node302);
    vector<int> res3 = {3, 3};
    assert(s.nodesBetweenCriticalPoints(&node301) == res3);
    return 0;
}
