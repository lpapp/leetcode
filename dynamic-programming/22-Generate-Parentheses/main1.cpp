#include <cassert>
#include <string>
#include <vector>

using namespace std;

class Solution {
    void addParen(vector<string>& result, int leftRemaining, int rightRemaining, string& str) {
        if (!leftRemaining && !rightRemaining) { result.push_back(str); return; }
        if (leftRemaining > 0) {
            str.push_back('(');
            addParen(result, leftRemaining - 1, rightRemaining, str);
            str.pop_back();
        }
        if (rightRemaining > leftRemaining) {
            str.push_back(')');
            addParen(result, leftRemaining, rightRemaining - 1, str);
            str.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        string str; str.reserve(2 * n);
        vector<string> result; result.reserve(1430);
        addParen(result, n, n, str);
        return result;
    }
};

int main()
{
    Solution solution;
    vector<string> res1 = {"((()))", "(()())", "(())()", "()(())", "()()()"};
    assert(solution.generateParenthesis(3) == res1);
    vector<string> res2 = {"()"};
    assert(solution.generateParenthesis(1) == res2);
    return 0;
}
