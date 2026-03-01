#include <array>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        array<size_t, 128> charFrequency = {0};
        for (const char c : s) ++charFrequency[c];
        size_t result = 0;
        for (const size_t frequency : charFrequency) result += (frequency / 2) * 2;
        if (result < s.size()) ++result;
        return result;
    }
};

int main()
{
	Solution s;
    cout << s.longestPalindrome("abccccdd") << endl;
    cout << s.longestPalindrome("a") << endl;
	return 0;
}
