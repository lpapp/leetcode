#include <cassert>
#include <string>

using namespace std;

class Solution {
    string buildFull(const string& h, char mid) {
        const int half = h.size();
        string res = h; res.reserve(2 * half + 1);
        if (mid) res += mid;
        for (int i = half - 1; i >= 0; --i) res += h[i];
        return res;
    }
    bool tailGreater(const string& h, char mid, const string& target) {
        const int half = h.size();
        int t = half;
        if (mid) {
            if (mid != target[t]) return mid > target[t];
            ++t;
        }
        for (int i = half - 1; i >= 0; --i, ++t) if (h[i] != target[t]) return 
h[i] > target[t];
        return false;
    }
public:
    string lexPalindromicPermutation(string s, string target) {
        const int n = s.size(), half = n / 2;
        int cnt[26] = {};
        for (const char c : s) ++cnt[c - 'a'];
        int odd = 0, oddChar = -1;
        for (int c = 0; c < 26; ++c) if (cnt[c] & 1) {
            if (++odd > (n & 1)) return "";
            oddChar = c;
        }
        const char mid = (n & 1) ? char('a' + oddChar) : 0;
        int freq[26] = {}, matched = 0;
        for (int c = 0; c < 26; ++c) freq[c] = cnt[c] / 2;
        string h(half, ' ');
        for (; matched < half && freq[target[matched] - 'a'] > 0; ++matched) {
            h[matched] = target[matched];
            --freq[target[matched] - 'a'];
        }
        if (matched == half && tailGreater(h, mid, target)) return buildFull(h, mid);
        for (int p = min(matched, half - 1); p >= 0; --p) {
            if (p < matched) ++freq[target[p] - 'a'];
            for (int c = target[p] - 'a' + 1; c < 26; ++c) if (freq[c] > 0) {
                h[p] = 'a' + c;
                --freq[c];
                for (int d = 0, q = p + 1; d < 26; ++d) for (int k = 0; k < freq[d]; ++k) h[q++] = 'a' + d;
                return buildFull(h, mid);
            }
        }
        return "";   
    }
};

int main()
{
    Solution s;
    assert(s.lexPalindromicPermutation("baba", "abba") == "baab");
    assert(s.lexPalindromicPermutation("baba", "bbaa") == "");
    assert(s.lexPalindromicPermutation("abc", "abb") == "");
    assert(s.lexPalindromicPermutation("aac", "abb") == "aca");
    return 0;
}
