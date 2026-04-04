#include <iostream>
#include <string>

using namespace std;

class Solution {
    bool isMatchingPair(char opening, char closing) {
        return (opening == '(' && closing == ')') || (opening == '[' && closing == ']') || (opening == '{' && closing == '}');
    }
public:
    bool isValid(string s) {
        string opening_parentheses;
        for (const char c : s) {
            if (c == '(' || c == '{' || c == '[') opening_parentheses.push_back(c);
            else if (opening_parentheses.empty() || !isMatchingPair(opening_parentheses.back(), c)) return false;
            else opening_parentheses.pop_back();
        }
        return opening_parentheses.empty();
    }
};

int main()
{
	Solution s;
	cout << s.isValid("()") << endl;
    cout << s.isValid("()[]{}") << endl;
    cout << s.isValid("(]") << endl;
    cout << s.isValid("([])") << endl;
    cout << s.isValid("([)]") << endl;
	return 0;
}
