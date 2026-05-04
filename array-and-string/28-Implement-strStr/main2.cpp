#include <cassert>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        int n = haystack.length(), m = needle.length();
        if (m > n) return -1;
        for (int i = 0; i <= n - m; ++i) if (haystack.substr(i, m) == needle) return i;
        return -1;
    }
};

int main()
{
 	Solution s;
	assert(!s.strStr("sadbutsad", "sad"));
	assert(s.strStr("leetcode", "leeto") == -1);
	return 0;
}
