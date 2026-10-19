#include <algorithm>
#include <cassert>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    long long countPalindromePaths(vector<int>& parent, string s) {
        const int n = parent.size();
        vector<int> mask(n, -1);
        mask[0] = 0;
        for (int i = 1; i < n; ++i) {
            if (mask[i] != -1) continue;
            vector<int> stack;
            int cur = i;
            while (mask[cur] == -1) { stack.push_back(cur); cur = parent[cur]; }
            int base = mask[cur];
            for (int j = (int)stack.size() - 1; j >= 0; --j) {
                const int node = stack[j];
                base ^= 1 << (s[node] - 'a');
                mask[node] = base;
            }
        }
        long long res = 0;
        unordered_map<int, int> seen; seen.reserve(n * 2);
        for (int i = 0; i < n; ++i) {
            const int m = mask[i];
            if (auto it = seen.find(m); it != seen.end()) res += it->second;
            for (int b = 0; b < 26; ++b) if (auto jt = seen.find(m ^ (1 << b)); jt != seen.end()) res += jt->second;
            ++seen[m];
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> parent1 = {-1, 0, 0, 1, 1, 2};
    assert(s.countPalindromePaths(parent1, "acaabc") == 8);
    vector<int> parent2 = {-1, 0, 0, 0, 0};
    assert(s.countPalindromePaths(parent2, "aaaaa") == 10);
    return 0;
}
