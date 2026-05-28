#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
    void dfs(int start, int remaining, vector<vector<int>>& res, vector<int>& current, vector<int>& candidates) {
        if (!remaining) { res.emplace_back(current); return; }
        if (remaining < candidates[start]) { return; }
        for (int j = start, n = candidates.size(); j < n; ++j) {
            current.push_back(candidates[j]);
            dfs(j, remaining - candidates[j], res, current, candidates);
            current.pop_back();
        }
    };
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> current;
        dfs(0, target, res, current, candidates);
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> candidates1 = {2, 3, 6, 7};
    vector<vector<int>> res1 = {{2, 2, 3}, {7}};
    assert(s.combinationSum(candidates1, 7) == res1);
    vector<int> candidates2 = {2, 3, 5};
    vector<vector<int>> res2 = {{2, 2, 2, 2}, {2, 3, 3}, {3, 5}};
    assert(s.combinationSum(candidates2, 8) == res2);
    vector<int> candidates3 = {2};
    vector<vector<int>> res3 = {};
    assert(s.combinationSum(candidates3, 1) == res3);
    return 0;
}
