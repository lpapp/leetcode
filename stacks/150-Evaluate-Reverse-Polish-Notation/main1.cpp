#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (const string& token : tokens) {
            if (token.size() > 1 || isdigit(token[0])) s.push(stoi(token));
            else {
                int second = s.top(); s.pop();
                int first = s.top(); s.pop();
                if (token[0] == '+') s.push(first + second);
                else if (token[0] == '-') s.push(first - second);
                else if (token[0] == '*') s.push(first * second);
                else s.push(first / second);
            }
        }
        return s.top();      
    }
};

int main()
{
	Solution s;
    vector<string> tokens1 = {"2", "1", "+", "3", "*"};
	cout << s.evalRPN(tokens1) << endl;
    vector<string> tokens2 = {"4", "13", "5", "/", "+"};
    cout << s.evalRPN(tokens2) << endl;
    vector<string> tokens3 = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    cout << s.evalRPN(tokens3) << endl;
	return 0;
}
