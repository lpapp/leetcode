#include <cassert>
#include <string>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sLength = s.size(), sIndex = 0;
        for (int tLength = t.size(), tIndex = 0; sIndex < sLength && tIndex < tLength; ++tIndex) if (s[sIndex] == t[tIndex]) ++sIndex;
      
        return sIndex == sLength;
    }
};

int main()
{
	Solution s;
    assert(s.isSubsequence("abc", "ahbgdc"));
    assert(!s.isSubsequence("axc", "ahbgdc"));
	return 0;
}
