#include <cassert>
#include <string>

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int cnt[26]{}, used[26]{};
        for (const char c : s) ++cnt[c - 'a'];
        string res;
        for (const char c : s) {
            --cnt[c - 'a'];
            if (used[c - 'a']) continue;
            while (!res.empty() && res.back() > c && cnt[res.back() - 'a']) { used[res.back() - 'a'] = 0; res.pop_back(); }
            res.push_back(c);
            used[c - 'a'] = 1;
        }
        return res;
    }
};

int main()
{
    Solution s;
    assert(s.removeDuplicateLetters("bcabc") == "abc");
    assert(s.removeDuplicateLetters("cbacdcbc") == "acdb");
    return 0;
}
