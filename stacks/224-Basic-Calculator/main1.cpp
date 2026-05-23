#include <cassert>
#include <cctype>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> stk;
        int res = 0;
        for (int i = 0, sign = 1, n = s.size(); i < n; ++i) {
            const char c = s[i];
            if (isdigit(c)) { long num; for (num = 0; i < n && isdigit(s[i]); ++i) num = num * 10 + (s[i] - '0'); --i; res += sign * num; }
            else if (c == '+') sign = 1;
            else if (c == '-') sign = -1;
            else if (c == '(') { stk.push(res); res = 0; stk.push(sign); sign = 1; }
            else if (c == ')') { int prevSign = stk.top(); stk.pop(); int prevResult = stk.top(); stk.pop(); res = prevResult + prevSign * res; }
        }
        return res;
    }
};

int main()
{
	Solution s;
	assert(s.calculate("1 + 1") == 2);
	assert(s.calculate(" 2-1 + 2 ") == 3);
	assert(s.calculate("(1+(4+5+2)-3)+(6+8)") == 23);
	assert(s.calculate("-2147483648") == -2147483648);
	return 0;
}
