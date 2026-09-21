#include <array>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
    int k;
    struct Node { int prod = 1; array<int, 5> cnt{}; };
    vector<Node> tree;
    vector<int> a;
    Node merge(const Node& L, const Node& R) const {
        Node res; res.prod = (L.prod * R.prod) % k; res.cnt = L.cnt;
        for (int r = 0; r < k; ++r) if (R.cnt[r]) res.cnt[(L.prod * r) % k] += R.cnt[r];
        return res;
    }
    Node makeLeaf(int v) const { Node res; res.prod = v % k; ++res.cnt[v % k]; return res; }
    void build(int node, int l, int r) {
        if (l == r) { tree[node] = makeLeaf(a[l]); return; }
        const int mid = (l + r) / 2;
        build(2 * node, l, mid);
        build(2 * node + 1, mid + 1, r);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }
    void update(int node, int l, int r, int pos, int v) {
        if (l == r) { tree[node] = makeLeaf(v); return; }
        const int mid = (l + r) / 2;
        if (pos <= mid) update(2 * node, l, mid, pos, v);
        else update(2 * node + 1, mid + 1, r, pos, v);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }
    void query(int node, int l, int r, int ql, int qr, Node& acc, bool& started) {
        if (qr < l || r < ql) return;
        if (ql <= l && r <= qr) { acc = started ? merge(acc, tree[node]) : tree[node]; started = true; return; }
        const int mid = (l + r) / 2;
        query(2 * node, l, mid, ql, qr, acc, started);
        query(2 * node + 1, mid + 1, r, ql, qr, acc, started);
    }
public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        this->k = k;
        a = nums;
        const int n = a.size();
        tree.assign(4 * n, Node{});
        build(1, 0, n - 1);
        vector<int> res;
        res.reserve(queries.size());
        for (const vector<int>& q : queries) {
            const int index = q[0], value = q[1], start = q[2], x = q[3];
            update(1, 0, n - 1, index, value);
            Node acc;
            bool started = false;
            query(1, 0, n - 1, start, n - 1, acc, started);
            res.push_back(acc.cnt[x]);
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {1, 2, 3, 4, 5};
    vector<vector<int>> queries1 = {{2, 2, 0, 2}, {3, 3, 3, 0}, {0, 1, 0, 1}};
    vector<int> res1 = {2, 2, 2};
    assert(s.resultArray(nums1, 3, queries1) == res1);
    vector<int> nums2 = {1, 2, 4, 8, 16, 32};
    vector<vector<int>> queries2 = {{0, 2, 0, 2}, {0, 2, 0, 1}};
    vector<int> res2 = {1, 0};
    assert(s.resultArray(nums2, 4, queries2) == res2);
    vector<int> nums3 = {1, 1, 2, 1, 1};
    vector<vector<int>> queries3 = {{2, 1, 0, 1}};
    vector<int> res3 = {5};
    assert(s.resultArray(nums3, 2, queries3) == res3);
    return 0;
}
