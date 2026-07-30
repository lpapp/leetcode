#include <algorithm>
#include <cassert>
#include <string>

using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        int freq[26] = {};
        for (const char c : word) ++freq[c - 'a'];
        ranges::sort(freq, greater{});
        int res = 0;
        for (int i = 0; i < 26 && freq[i]; ++i) res += (i / 8 + 1) * freq[i];
        return res;
    }
};

int main()
{
    Solution s;
    assert(s.minimumPushes("abcde") == 5);
    assert(s.minimumPushes("xyzxyzxyzxyz") == 12);
    assert(s.minimumPushes("aabbccddeeffgghhiiiiii") == 24);
    return 0;
}
