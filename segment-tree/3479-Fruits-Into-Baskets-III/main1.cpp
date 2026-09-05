#include <cassert>
#include <vector>

using namespace std;

class SegmentTree {
    vector<int> maxRange;
    int n;
    void build(int node, int left, int right, const vector<int>& baskets) {
        if (left == right) { maxRange[node] = baskets[left - 1]; return; }
        const int mid = (left + right) >> 1;
        build(node * 2, left, mid, baskets);
        build(node * 2 + 1, mid + 1, right, baskets);
        maxRange[node] = max(maxRange[node * 2], maxRange[node * 2 + 1]);
    }
    void modify(int node, int left, int right, int pos, int val) {
        if (left == right) { maxRange[node] = val; return; }
        const int mid = (left + right) >> 1;
        if (pos <= mid) modify(node * 2, left, mid, pos, val);
        else modify(node * 2 + 1, mid + 1, right, pos, val);
        maxRange[node] = max(maxRange[node * 2], maxRange[node * 2 + 1]);
    }
public:
    SegmentTree(vector<int>& baskets) {
        n = baskets.size();
        maxRange.assign(4 * n, 0);
        build(1, 1, n, baskets);
    }
    int query(int node, int left, int right, int v) {
        if (maxRange[node] < v) return -1;
        if (left == right) return left;
        const int mid = (left + right) >> 1;
        if (maxRange[node * 2] >= v) return query(node * 2, left, mid, v);
        return query(node * 2 + 1, mid + 1, right, v);
    }
    void modify(int pos, int val) { modify(1, 1, n, pos, val); }
};

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        const int n = baskets.size();
        SegmentTree tree(baskets);
        int unplaced = 0;
        for (const int fruit : fruits) {
            const int pos = tree.query(1, 1, n, fruit);
            if (pos < 0) ++unplaced;
            else tree.modify(pos, 0);
        }
        return unplaced;      
    }
};

int main()
{
    Solution s;
    vector<int> fruits1 = {4, 2, 5};
    vector<int> baskets1 = {3, 6, 1};
    assert(s.numOfUnplacedFruits(fruits1, baskets1) == 1);
    vector<int> fruits2 = {3, 6, 1};
    vector<int> baskets2 = {6, 4, 7};
    assert(s.numOfUnplacedFruits(fruits2, baskets2) == 0);
    return 0;
}
