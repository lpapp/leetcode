#include <array>
#include <cassert>
#include <string>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        array<int, 128> tHash = {0}, slidingWindowHash = {0};
        for (const char c : t) ++tHash[c];
        int sLength = s.length(), minStart = -1, minLength = sLength + 1;
        for (int left = 0, right = 0, tLength = t.length(), tCount = 0; right < sLength; ++right) {
            const char rc = s[right];
            if (++slidingWindowHash[rc] <= tHash[rc]) ++tCount;
            for (; tCount == tLength; ++left) {
                if (right - left + 1 < minLength) { minLength = right - left + 1; minStart = left; }
                const char lc = s[left];
                if (slidingWindowHash[lc] <= tHash[lc]) --tCount;
                --slidingWindowHash[lc];
            }
        }
        return minStart == -1 ? "" : s.substr(minStart, minLength);       
    }
};

int main()
{
	Solution s;
    assert(s.minWindow("ADOBECODEBANC", "ABC") == "BANC");
    assert(s.minWindow("a", "a") == "a");
    assert(s.minWindow("a", "aa") == "");
	return 0;
}
