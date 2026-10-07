#include <algorithm>
#include <cassert>
#include <functional>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int left = 0, right = 0, n = s.size();
        for (const char c : s) if (c == '(') ++left; else if (c == ')') { if (left) --left; else ++right; }
        unordered_set<string> res;
        string cur; cur.reserve(n);
        function<void(int, int, int, int, int)> dfs = [&](int i, int l, int r, int lcnt, int rcnt) {
            if (i == n) { if (!l && !r) res.insert(cur); return; }
            if (n - i < l + r || lcnt < rcnt) return;
            if (s[i] == '(' && l > 0) dfs(i + 1, l - 1, r, lcnt, rcnt);
            if (s[i] == ')' && r > 0) dfs(i + 1, l, r - 1, lcnt, rcnt);
            cur.push_back(s[i]);
            dfs(i + 1, l, r, lcnt + (s[i] == '('), rcnt + (s[i] == ')'));
            cur.pop_back();
        };
        dfs(0, left, right, 0, 0);
        return vector<string>(res.cbegin(), res.cend());
    }
};

static vector<string> sortedOf(vector<string> v) {
    ranges::sort(v);
    return v;
}

int main()
{
    Solution s;
    vector<string> res1 = {"(())()", "()()()"};
    assert(s.removeInvalidParentheses("()())()") == sortedOf(res1));
    vector<string> res2 = {"(a())()", "(a)()()"};
    assert(s.removeInvalidParentheses("(a)())()") == sortedOf(res2));
    vector<string> res3 = {""};
    assert(s.removeInvalidParentheses(")(") == sortedOf(res3));
    return 0;
}
