#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
    int dfs(int index, vector<int>& arr, int d, vector<int>& dp) {
        if (dp[index]) return dp[index];
        int res = 1;
        for (int j = index - 1; j >= 0; --j) {
            if (index - j > d || arr[j] >= arr[index]) break;
            res = max(res, 1 + dfs(j, arr, d, dp));
        }
        for (int j = index + 1, n = arr.size(); j < n; ++j) {
            if (j - index > d || arr[j] >= arr[index]) break;
            res = max(res, 1 + dfs(j, arr, d, dp));
        }
        dp[index] = res;
        return res;
    };    
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> dp(n, 0);
        int res = 1;
        for (int i = 0; i < n; ++i) res = max(res, dfs(i, arr, d, dp));
        return res;
    }
};

int main()
{
	Solution s;
	vector<int> arr1 = {6, 4, 14, 6, 8, 13, 9, 7, 10, 6, 12};
	assert(s.maxJumps(arr1, 2) == 4);
	vector<int> arr2 = {3, 3, 3, 3, 3};
	assert(s.maxJumps(arr2, 3) == 1);
	vector<int> arr3 = {7, 6, 5, 4, 3, 2, 1};
	assert(s.maxJumps(arr3, 1) == 7);
	return 0;
}
