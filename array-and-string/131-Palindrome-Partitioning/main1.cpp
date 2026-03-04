#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
	void dfs(size_t startIndex, size_t length, vector<string>& currentPartition, vector<vector<string>>& result, const vector<vector<bool>>& dp, const string& s) {
    	if (startIndex == length) {
        	result.push_back(currentPartition);
            return;
        }
          
        for (size_t endIndex = startIndex; endIndex < length; ++endIndex) {
        	if (dp[startIndex][endIndex]) {
            	currentPartition.push_back(s.substr(startIndex, endIndex - startIndex + 1));
                dfs(endIndex + 1, length, currentPartition, result, dp, s);
                currentPartition.pop_back();
            }
        }
    };
public:
    vector<vector<string>> partition(string s) {
        const size_t sLength = s.size();
        vector<vector<bool>> dp(sLength, vector<bool>(sLength, true));
        for (int i = sLength - 1; i >= 0; --i) {
            for (size_t j = i + 1; j < sLength; ++j) {
                dp[i][j] = (s[i] == s[j]) && dp[i + 1][j - 1];
            }
        }
        vector<vector<string>> result;
        vector<string> currentPartition;
        dfs(0, sLength, currentPartition, result, dp, s);
        return result;
    }
};

void printVectorVector(const vector<vector<string>>& input)
{
    cout << "[";
    for (const vector<string>& v: input) {
        cout << "[";
        for (const string& s: v) {
            cout << s << ",";
        }
        cout << "],";
    }
    cout << "]" << endl;
}

int main()
{
	Solution s;
    printVectorVector(s.partition("aab"));
    printVectorVector(s.partition("a"));
	return 0;
}
