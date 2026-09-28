#include <cassert>
#include <vector>

using namespace std;

class Solution {
	void dfs(int number, vector<int>& combination, int n, int k, vector<vector<int>>& result) {
	    if (static_cast<int>(combination.size()) == k) { result.push_back(combination); return; }
	    if (number > n) return;
	    combination.push_back(number);
	    dfs(number + 1, combination, n, k, result);
	    combination.pop_back();
	    dfs(number + 1, combination, n, k, result);
	};
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> combination;
        dfs(1, combination, n, k, result);
        return result;
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
