#include <algorithm>
#include <cassert>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        string cur;
        for (const char c : s) {
            if (c == '(') { st.push(cur); cur.clear(); }
            else if (c == ')') {
                reverse(cur.begin(), cur.end());
                cur = st.top() + cur;
                st.pop();
            }
            else cur += c;
        }
        return cur;
    }
};

int main()
{
    Solution s;
    assert(s.reverseParentheses("(abcd)") == "dcba");
    assert(s.reverseParentheses("(u(love)i)") == "iloveu");
    assert(s.reverseParentheses("(ed(et(oc))el)") == "leetcode");
    return 0;
}
