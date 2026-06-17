#include <algorithm>
#include <cassert>
#include <string>

using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
    	int hash1[26]{}, hash2[26]{};
    	for (char character : word1) ++hash1[character - 'a'];
    	for (char character : word2) ++hash2[character - 'a'];
    	for (int i = 0; i < 26; ++i) if (!hash1[i] != !hash2[i]) return false;
    	sort(hash1, hash1 + 26);
    	sort(hash2, hash2 + 26);
    	return equal(hash1, hash1 + 26, hash2);
    }
};

int main()
{
    Solution s;
    assert(s.closeStrings("abc", "bca"));
    assert(!s.closeStrings("a", "aa"));
    assert(s.closeStrings("cabbba", "abbccc"));
    return 0;
}
