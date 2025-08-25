#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
    bool isSubsequence(const string& a, const string& b) {
        size_t indexB = 0;
        for (size_t i = 0; i < a.size() && indexB < b.size(); ++i) if (a[i] == b[indexB]) ++indexB;
        return indexB == b.size();
    }
public:
    int findLUSlength(vector<string>& strs) {
        int result = -1;
        for (size_t i = 0, j = 0, n = strs.size(); i < n; ++i) {
            for (j = 0; j < n; ++j) {
                if (i == j) continue;
                if (isSubsequence(strs[j], strs[i])) break;
            }

            if (j == n) result = max(result, static_cast<int>(strs[i].size()));

        }
        return result;
    }
};

int main()
{
	Solution solution;
	vector<string> input1 = {"aba", "cdc", "eae"};
	cout << solution.findLUSlength(input1) << endl;

	vector<string> input2 = {"aaa", "aaa", "aa"};
	cout << solution.findLUSlength(input2) << endl;

	return 0;
}
