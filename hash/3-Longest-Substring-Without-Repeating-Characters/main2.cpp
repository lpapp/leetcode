#include <algorithm>
#include <array>
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_set<char> charSet;
        size_t result = 0;
        for (size_t start = 0, end = 0; end < s.size(); ++end) {
            const char endChar = s[end];
            while (charSet.contains(endChar)) charSet.erase(s[start++]);
            charSet.insert(endChar);
            result = max(result, end - start + 1);

        }
        return result;
    }
};

int main()
{
	Solution s;
    cout << s.lengthOfLongestSubstring("abcabcbb") << endl;
    cout << s.lengthOfLongestSubstring("bbbbb") << endl;
    cout << s.lengthOfLongestSubstring("pwwkew") << endl;
	return 0;
}
