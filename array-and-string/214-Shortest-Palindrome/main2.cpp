#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        constexpr int BASE = 131;
        uint64_t powerMultiplier = 1, forwardHash = 0, reverseHash = 0;
        size_t longestPalindromicPrefixLength = 0;
        const size_t sLength = s.size();
        for (size_t i = 0; i < sLength; ++i, powerMultiplier *= BASE) {
            const int charValue = s[i] - 'a' + 1;
            forwardHash = forwardHash * BASE + charValue;
            reverseHash = reverseHash + powerMultiplier * charValue;
            if (forwardHash == reverseHash) longestPalindromicPrefixLength = i + 1;
        }
        if (longestPalindromicPrefixLength == sLength) return s;
        string nonPalindromicSuffix = s.substr(longestPalindromicPrefixLength, 
                                                sLength - longestPalindromicPrefixLength);
        reverse(nonPalindromicSuffix.begin(), nonPalindromicSuffix.end());
        return nonPalindromicSuffix + s;
    }
};

int main()
{
	Solution s;
    cout << s.shortestPalindrome("aacecaaa") << endl;
    cout << s.shortestPalindrome("abcd") << endl;
	return 0;
}
