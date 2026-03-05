#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        const size_t sLength = s.size();
        vector<int> current(sLength), previous(sLength);
        for (int i = sLength - 1; i >= 0; --i, previous = current) {
            current[i] = 1;
            for (size_t j = i + 1; j < sLength; ++j) {
                if (s[i] == s[j]) current[j] = previous[j - 1] + 2;
                else current[j] = max(previous[j], current[j - 1]);
            }
        }
        return current[sLength - 1];
    }
};

int main()
{
	Solution s;
    cout << s.longestPalindromeSubseq("bbbab") << endl;
    cout << s.longestPalindromeSubseq("cbbd") << endl;
	return 0;
}
