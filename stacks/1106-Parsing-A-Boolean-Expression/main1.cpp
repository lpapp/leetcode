#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool parseBoolExpr(string expression) {
		stack<char> s;
        for (const char c : expression) {
            if (c != '(' && c != ')' && c != ',') s.push(c);
            else if (c == ')') {
                int trueCount = 0, falseCount = 0;
                for (char t = s.top(); t == 't' || t == 'f'; t = s.top()) {
                    if (t == 't') ++trueCount;
                    else ++falseCount;
                    s.pop();
                }

                const char op = s.top(); s.pop();
                char result;
                if (op == '!') result = (falseCount > 0) ? 't' : 'f';
                else if (op == '&') result = (falseCount > 0) ? 'f' : 't';
                else if (op == '|') result = (trueCount > 0) ? 't' : 'f';
                s.push(result);
            }
        }

        return s.top() == 't';
    }
};

int main()
{
	Solution s;
	cout << s.parseBoolExpr("&(|(f))") << endl;
    cout << s.parseBoolExpr("|(f,f,f,t)") << endl;
    cout << s.parseBoolExpr("!(&(f,t))") << endl;
	return 0;
}
