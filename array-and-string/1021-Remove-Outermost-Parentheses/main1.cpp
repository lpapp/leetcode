#include <cassert>
#include <string>

using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        string result; result.reserve(s.size());
        for (int depth = 0; const char ch : s) {
            if (ch == '(') { if (++depth > 1) result.push_back(ch); }
            else { if (--depth > 0) result.push_back(ch); }
        }
        return result;
    }
};

int main()
{
    Solution s;
    assert(s.removeOuterParentheses("(()())(())") == "()()()");
    assert(s.removeOuterParentheses("(()())(())(()(()))") == "()()()()(())");
    assert(s.removeOuterParentheses("()()") == "");
    return 0;
}
