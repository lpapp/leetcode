#include <cassert>
#include <string>

using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
    	const int n = word.size();
    	if (n <= 1) return true;
    	bool first = isupper(word[0]), second = isupper(word[1]);
    	for (int i = 2; i < n; ++i) if (!!isupper(word[i]) != second) return false;
    	return first || !second;
    }
};

int main()
{
    Solution s;
    assert(s.detectCapitalUse("USA"));
    assert(!s.detectCapitalUse("FlaG"));
    return 0;
}
