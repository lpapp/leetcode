#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using namespace std;

class Solution {
	int dfs(string s, int left, int right, vector<vector<int>>& dp) {
	    if (left >= right) return 0;
	    if (dp[left][right] != -1) return dp[left][right];
	    int result = std::numeric_limits<int>::max();
	    if (s[left] == s[right]) result = dfs(s, left + 1, right - 1, dp);
	    else result = min(dfs(s, left + 1, right, dp), dfs(s, left, right - 1, dp)) + 1;
	    return dp[left][right] = result;
	};
public:
    int minInsertions(string s) {
        const size_t sLength = s.size();
        vector<vector<int>> dp(sLength, vector<int>(sLength, -1));
        return dfs(s, 0, sLength - 1, dp);
    }
};

int main()
{
	Solution s;
    cout << s.minInsertions("zzazz") << endl;
    cout << s.minInsertions("mbadm") << endl;
    cout << s.minInsertions("leetcode") << endl;
	return 0;
}
