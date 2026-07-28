#include <cassert>
#include <string>

using namespace std;

class Solution {
public:
    string smallestPalindrome(string s) {
        const int n = s.size(), half = n / 2;
        int freq[26] = {};
        for (int i = 0; i < half; ++i) ++freq[s[i] - 'a'];
        string res; res.reserve(n);
        for (int i = 0; i < 26; ++i) res.append(freq[i], 'a' + i);
        if (n & 1) res += s[half];
        for (int i = 25; i >= 0; --i) res.append(freq[i], 'a' + i);
        return res;
    }
};

int main()
{
    Solution s;
    assert(s.smallestPalindrome("z") == "z");
    assert(s.smallestPalindrome("babab") == "abbba");
    assert(s.smallestPalindrome("daccad") == "acddca");
    return 0;
}
