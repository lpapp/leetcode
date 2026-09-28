#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> comb(k);
        for (int i = 0; i < k; ++i) comb[i] = i + 1;
        while (true) {
            res.push_back(comb);
            int i = k - 1;
            while (i >= 0 && comb[i] == n - k + 1 + i) --i;
            if (i < 0) break;
            ++comb[i];
            for (int j = i + 1; j < k; ++j) comb[j] = comb[j - 1] + 1;
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> res1 = {{1, 2}, {1, 3}, {1, 4}, {2, 3}, {2, 4}, {3, 4}};
    assert(s.combine(4, 2) == res1);
    vector<vector<int>> res2 = {{1}};
    assert(s.combine(1, 1) == res2);
    return 0;
}
