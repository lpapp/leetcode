#include <algorithm>
#include <array>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        array<int, 128> hash = {0};
        int result = 0;
        const int sLength = s.size();
        for (int left = 0, right = 0; right < sLength; ++right) {
            for (++hash[s[right]]; hash[s[right]] > 1; ++left) --hash[s[left]];
            result = max(result, right - left + 1);
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
