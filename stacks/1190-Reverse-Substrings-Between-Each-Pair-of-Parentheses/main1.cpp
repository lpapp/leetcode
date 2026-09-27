#include <cassert>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        const int n = s.size();
        vector<int> match(n);
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') st.push(i);
            else if (s[i] == ')') {
                const int j = st.top(); st.pop();
                match[i] = j;
                match[j] = i;
            }
        }
        string res; res.reserve(n);
        for (int i = 0, dir = 1; i < n; i += dir) {
            if (s[i] == '(' || s[i] == ')') { i = match[i]; dir = -dir; }
            else res += s[i];
        }
        return res;
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
