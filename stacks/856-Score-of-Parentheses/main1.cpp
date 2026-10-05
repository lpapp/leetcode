#include <cassert>
#include <string>

using namespace std;

class Solution {
public:
    int scoreOfParentheses(string s) {
        int res = 0;
        for (int i = 0, depth = 0, n = s.size(); i < n; ++i) {
            if (s[i] == '(') ++depth;
            else if (s[i - 1] == '(') res += 1 << --depth;
            else --depth;
        }
        return res;
    }
};

int main()
{
    Solution s;
    assert(s.scoreOfParentheses("()") == 1);
    assert(s.scoreOfParentheses("(())") == 2);
    assert(s.scoreOfParentheses("()()") == 2);
    return 0;
}
