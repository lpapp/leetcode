#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkPartitioning(string s) {
        const size_t sLength = s.size();
        vector<vector<bool>> isPalindrome(sLength, vector<bool>(sLength, true));
        for (int left = sLength - 1; left >= 0; --left) {
            for (size_t right = left + 1; right < sLength; ++right) {
                isPalindrome[left][right] = (s[left] == s[right]) && (right - left == 1 || isPalindrome[left + 1][right - 1]);
            }
        }
      
        for (size_t firstSplit = 0; firstSplit < sLength - 2; ++firstSplit) {
            for (size_t secondSplit = firstSplit + 1; secondSplit < sLength - 1; ++secondSplit) {
                if (isPalindrome[0][firstSplit] && isPalindrome[firstSplit + 1][secondSplit] && isPalindrome[secondSplit + 1][sLength - 1]) return true;
            }
        }
      
        return false;
    }
};

int main()
{
	Solution s;
    cout << s.checkPartitioning("abcbdd") << endl;
    cout << s.checkPartitioning("bcbddxy") << endl;
	return 0;
}
