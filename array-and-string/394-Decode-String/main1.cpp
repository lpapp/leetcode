#include <iostream>
#include <stack>
#include <string>
#include <utility>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
    	string result;
    	stack<pair<string, int>> recursiveStack;
    	int repeatCount = 0;
  
    	for (const char c : s) {
    	    if (isdigit(c)) repeatCount = repeatCount * 10 + (c - '0');
    	    else if (isalpha(c)) result += c;
    	    else if (c == '[') {
    	        recursiveStack.push({result, repeatCount});
    	        result = "";
    	        repeatCount = 0;
    	    } else if (c == ']') {
    	        const auto [previousString, previousRepeatCount] = recursiveStack.top();
    	        recursiveStack.pop();
    	        string repeatedString;
    	        for (int i = 0; i < previousRepeatCount; ++i) repeatedString += result;
    	        result = previousString + repeatedString;
    	    }
    	}
  
    	return result;
    }
};

int main()
{
	Solution s;
    cout << s.decodeString("3[a]2[bc]") << endl;
    cout << s.decodeString("3[a2[c]]") << endl;
    cout << s.decodeString("2[abc]3[cd]ef") << endl;
	return 0;
}
