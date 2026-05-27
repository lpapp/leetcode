#include <array>
#include <cassert>
#include <string>

using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        array<int, 'z' + 1> upperHash = {0}, lowerHash = {0};
        for (int i = 0, n = word.size(); i < n; ++i) {
            const char c = word[i];
            const int pos = i + 1;
            if (!upperHash[c]) upperHash[c] = pos;
            lowerHash[c] = pos;
        }
        int res = 0;
        for (int i = 0; i < 26; ++i) {
            char lower = 'a' + i, upper = 'A' + i;
            if (lowerHash[lower] > 0 && upperHash[upper] > 0 && lowerHash[lower] < upperHash[upper]) ++res;
        }
        return res;
    }
};

int main()
{
	Solution s;
	assert(s.numberOfSpecialChars("aaAbcBC") == 3);
	assert(!s.numberOfSpecialChars("abc"));
	assert(!s.numberOfSpecialChars("AbBCab"));
	return 0;
}
