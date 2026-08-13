#include <cassert>
#include <string>
#include <vector>

using namespace std;

class Solution {
    struct Node { int lmx, rmx, mx; };
    vector<Node> tree;
    string s;
    int n;
    void pushup(int u, int l, int r) {
        const Node& lc = tree[u << 1];
        const Node& rc = tree[u << 1 | 1];
        const int mid = (l + r) >> 1;
        const int lLen = mid - l + 1, rLen = r - mid;
        const bool match = s[mid] == s[mid + 1];
        tree[u].lmx = lc.lmx + (lc.lmx == lLen && match ? rc.lmx : 0);
        tree[u].rmx = rc.rmx + (rc.rmx == rLen && match ? lc.rmx : 0);
        tree[u].mx = max({lc.mx, rc.mx, match ? lc.rmx + rc.lmx : 0});
    }
    void build(int u, int l, int r) {
        if (l == r) { tree[u] = {1, 1, 1}; return; }
        const int mid = (l + r) >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushup(u, l, r);
    }
    void modify(int u, int l, int r, int pos) {
        if (l == r) return;
        const int mid = (l + r) >> 1;
        if (pos <= mid) modify(u << 1, l, mid, pos);
        else modify(u << 1 | 1, mid + 1, r, pos);
        pushup(u, l, r);
    }
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        this->s = std::move(s);
        n = this->s.size();
        tree.resize(4 * n);
        build(1, 0, n - 1);
        const int k = queryIndices.size();
        vector<int> res(k);
        for (int i = 0; i < k; ++i) {
            this->s[queryIndices[i]] = queryCharacters[i];
            modify(1, 0, n - 1, queryIndices[i]);
            res[i] = tree[1].mx;
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> queryIndices1 = {1, 3, 3};
    vector<int> res1 = {3, 3, 4};
    assert(s.longestRepeating("babacc", "bcb", queryIndices1) == res1);
    vector<int> queryIndices2 = {2, 1};
    vector<int> res2 = {2, 3};
    assert(s.longestRepeating("abyzz", "aa", queryIndices2) == res2);
    return 0;
}
