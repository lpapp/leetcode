#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int palindromePartition(string s, int k) {
        const int sLength = s.size();
        vector<vector<int>> changesNeeded(sLength, vector<int>(sLength, 0));
        for (int left = sLength - 1; left >= 0; --left) {
            for (int right = left; right < sLength; ++right) {
                changesNeeded[left][right] = (s[left] != s[right]) ? 1 : 0;
                if (left + 1 < right) changesNeeded[left][right] += changesNeeded[left + 1][right - 1];
            }
        }
      
        vector<vector<int>> dp(sLength + 1, vector<int>(k + 1, 0));
        for (int length = 1; length <= sLength; ++length) {
            for (int partitions = 1; partitions <= min(length, k); ++partitions) {
                if (partitions == 1) dp[length][partitions] = changesNeeded[0][length - 1];
                else {
                    dp[length][partitions] = numeric_limits<int>::max();
                  
                    for (int splitPoint = partitions - 1; splitPoint < length; ++splitPoint) {
                        dp[length][partitions] = min(dp[length][partitions], 
                                                    dp[splitPoint][partitions - 1] + changesNeeded[splitPoint][length - 1]);
                    }
                }
            }
        }
      
        return dp[sLength][k];
    }
};

int main()
{
	Solution s;
    cout << s.palindromePartition("abc", 2) << endl;
    cout << s.palindromePartition("aabbc", 3) << endl;
    cout << s.palindromePartition("leetcode", 8) << endl;
	return 0;
}
