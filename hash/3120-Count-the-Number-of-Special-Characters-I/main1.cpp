#include <array>
#include <cassert>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        array<bool, 'z' + 1> hash = {};
        for (const char c : word) hash[c] = true;
        int res = 0;
        for (int i = 0; i < 26; ++i) if (hash['a' + i] && hash['A' + i]) ++res;
        return res;
    }
};

int main()
{
	Solution s;
	assert(s.numberOfSpecialChars("aaAbcBC") == 3);
	assert(!s.numberOfSpecialChars("abc"));
	assert(s.numberOfSpecialChars("abBCab") == 1);
	return 0;
}
