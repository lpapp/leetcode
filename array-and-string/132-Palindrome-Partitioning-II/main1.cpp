#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minCut(string s) {
        const size_t sLength = s.size();
        vector<vector<bool>> isPalindrome(sLength, vector<bool>(sLength, true));
      
        for (int start = sLength - 1; start >= 0; --start) {
            for (size_t end = start + 1; end < sLength; ++end) {
                isPalindrome[start][end] = (s[start] == s[end]) && isPalindrome[start + 1][end - 1];
            }
        }
      
        vector<int> minCuts(sLength);
        for (size_t i = 0; i < sLength; ++i) minCuts[i] = i;
        for (size_t end = 1; end < sLength; ++end) {
            for (size_t start = 0; start <= end; ++start) {
                if (!isPalindrome[start][end]) continue;
                if (!start) minCuts[end] = 0;
                else minCuts[end] = min(minCuts[end], minCuts[start - 1] + 1);
            }
        }
        return minCuts[sLength - 1];
    }
};

int main()
{
	Solution s;
    cout << s.minCut("aab") << endl;
    cout << s.minCut("a") << endl;
    cout << s.minCut("ab") << endl;
	return 0;
}
