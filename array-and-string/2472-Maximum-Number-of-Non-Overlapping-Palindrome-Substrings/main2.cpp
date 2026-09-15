#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
	int dfs(size_t start, int k, size_t sLength, vector<int>& memo, const vector<vector<bool>>& isPalindrome) {
	    if (start >= sLength) return 0;
	    if (memo[start] != -1) return memo[start];
	    int maxCount = dfs(start + 1, k, sLength, memo, isPalindrome);
	    for (size_t end = start + k - 1; end < sLength; ++end) {
	        if (isPalindrome[start][end]) maxCount = max(maxCount, 1 + dfs(end + 1, k, sLength, memo, isPalindrome));
	    }
	    memo[start] = maxCount;
	    return maxCount;
	};
public:
    int maxPalindromes(string s, int k) {
        const size_t sLength = s.size();
        vector<vector<bool>> isPalindrome(sLength, vector<bool>(sLength, true));
        vector<int> memo(sLength, -1);
        for (int left = sLength - 1; left >= 0; --left) {
            for (size_t right = left + 1; right < sLength; ++right) {
                isPalindrome[left][right] = (s[left] == s[right]) && 
                                           isPalindrome[left + 1][right - 1];
            }
        }
		return dfs(0, k, sLength, memo, isPalindrome);
    }
};

int main()
{
	Solution s;
    cout << s.maxPalindromes("abaccdbbd", 3) << endl;
    cout << s.maxPalindromes("adbcda", 2) << endl;
	return 0;
}
