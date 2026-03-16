#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        const size_t word1Length = word1.size(), word2Length = word2.size();
        vector<vector<int>> dp(word1Length + 1, vector<int>(word2Length + 1, 0));
        for (size_t j = 0; j <= word2Length; ++j) dp[0][j] = j;
        for (size_t i = 1; i <= word1Length; ++i) {
            dp[i][0] = i;
            for (size_t j = 1; j <= word2Length; ++j) {
                if (word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                else dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
            }
        }
        return dp[word1Length][word2Length];      
    }
};

int main()
{
	Solution s;
    cout << s.minDistance("horse", "ros") << endl;
    cout << s.minDistance("intention", "execution") << endl;
	return 0;
}
