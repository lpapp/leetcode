#include <cassert>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        const int n = parent.size();
        vector<int> start(n + 1), child(n), order, res(n, 1);
        order.reserve(n);
        for (int i = 1; i < n; ++i) ++start[parent[i] + 1];
        for (int i = 0; i < n; ++i) start[i + 1] += start[i];
        for (int i = 1; i < n; ++i) child[start[parent[i]]++] = i;
        for (int i = n; i > 0; --i) start[i] = start[i - 1];
        start[0] = 0;
        for (vector<int> st{0}, saved(n), last(26, -1); !st.empty();) {
            const int u = st.back();
            st.pop_back();
            if (u < 0) {
                last[s[~u] - 'a'] = saved[~u];
                continue;
            }
            const int c = s[u] - 'a';
            if (u && last[c] >= 0) parent[u] = last[c];
            saved[u] = last[c], last[c] = u;
            order.push_back(u);
            st.push_back(~u);
            for (int i = start[u]; i < start[u + 1]; ++i) st.push_back(child[i]);
        }
        for (int i = n - 1; i > 0; --i) res[parent[order[i]]] += res[order[i]];
        return res;       
    }
};

int main()
{
    Solution s;
    vector<int> parent1 = {-1, 0, 0, 1, 1, 1};
    vector<int> res1 = {6, 3, 1, 1, 1, 1};
    assert(s.findSubtreeSizes(parent1, "abaabc") == res1);
    vector<int> parent2 = {-1, 0, 4, 0, 1};
    vector<int> res2 = {5, 2, 1, 1, 1};
    assert(s.findSubtreeSizes(parent2, "abbba") == res2);
    return 0;
}
