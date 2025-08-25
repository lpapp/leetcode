#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
    	const size_t size1 = text1.size();
    	const size_t size2 = text2.size();
    	vector<int> previousRow(size2 + 1, 0), currentRow(size2 + 1, 0);

        for (size_t i1 = 1; i1 <= size1; ++i1) {
            for (size_t i2 = 1; i2 <= size2; ++i2) {
                if (text1[i1 - 1] == text2[i2 - 1]) currentRow[i2] = 1 + previousRow[i2 - 1];
                else currentRow[i2] = max(previousRow[i2], currentRow[i2 - 1]);
            }
          
            previousRow = currentRow;
        }
  
        return previousRow[size2];
    }
};

int main()
{
	Solution solution;
	cout << solution.longestCommonSubsequence("abcde", "ace") << endl;
	cout << solution.longestCommonSubsequence("abc", "abc") << endl;
	cout << solution.longestCommonSubsequence("abc", "def") << endl;
	return 0;
}
