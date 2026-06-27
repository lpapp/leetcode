#include <cassert>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPrefix(string s) {
        const int n = s.size();
        vector<int> lps(n, 0);
        for (int i = 1, len = 0; i < n;) {
            if (s[i] == s[len]) lps[i++] = ++len;
            else if (len) len = lps[len - 1];
            else lps[i++] = 0;
        }
        return s.substr(0, lps[n - 1]);
    }
};

int main()
{
	Solution s;
	assert(s.longestPrefix("level") == "l");
	assert(s.longestPrefix("ababab") == "abab");
	return 0;
}
