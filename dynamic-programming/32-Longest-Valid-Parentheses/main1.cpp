#include <cassert>
#include <string>

using namespace std;

class Solution {
    int scan(const string& s, char openChar, bool forward) const {
        int res = 0;
        for (int k = 0, n = s.size(), open = 0, close = 0; k < n; ++k) {
            const char c = forward ? s[k] : s[n - 1 - k];
            if (c == openChar) ++open; else ++close;
            if (close > open) open = close = 0;
            else if (open == close) res = max(res, 2 * open);
        }
        return res;
    }
public:
    int longestValidParentheses(string s) {
        return max(scan(s, '(', true), scan(s, ')', false));
    }
};

int main()
{
    Solution s;
    assert(s.longestValidParentheses("(()") == 2);
    assert(s.longestValidParentheses(")()())") == 4);
    assert(s.longestValidParentheses("") == 0);
    return 0;
}
