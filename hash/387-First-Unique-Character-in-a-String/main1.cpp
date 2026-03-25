#include <array>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        array<int, 26> charFrequency = {0};
        for (const char c : s) ++charFrequency[c - 'a'];
        const size_t sLength = s.size();
        for (size_t i = 0; i < sLength; ++i) if (charFrequency[s[i] - 'a'] == 1) return i;
        return -1;
    }
};

int main()
{
	Solution s;
    cout << s.firstUniqChar("leetcode") << endl;
    cout << s.firstUniqChar("loveleetcode") << endl;
    cout << s.firstUniqChar("aabb") << endl;
	return 0;
}
