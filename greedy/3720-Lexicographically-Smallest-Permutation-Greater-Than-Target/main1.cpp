#include <cassert>
#include <string>

using namespace std;

class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size(), matched = 0, freq[26] = {};
        for (const char c : s) ++freq[c - 'a'];
        for (; matched < n && freq[target[matched] - 'a'] > 0; ++matched) --freq[target[matched] - 'a'];
        for (int p = min(matched, n - 1); p >= 0; --p) {
            if (p < matched) ++freq[target[p] - 'a'];
            for (int c = target[p] - 'a' + 1; c < 26; ++c) if (freq[c] > 0) {
                string res; res.reserve(n); res.append(target, 0, p); res += 'a' + c;
                --freq[c];
                for (int d = 0; d < 26; ++d) res.append(freq[d], 'a' + d);
                return res;
            }
        }
        return "";
    }
};

int main()
{
    Solution s;
    assert(s.lexGreaterPermutation("abc", "bba") == "bca");
    assert(s.lexGreaterPermutation("leet", "code") == "eelt");
    assert(s.lexGreaterPermutation("baba", "bbaa") == "");
    return 0;
}
