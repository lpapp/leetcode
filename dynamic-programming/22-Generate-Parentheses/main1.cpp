#include <iostream>
#include <vector>

using namespace std;

class Solution {
    void addParen(vector<string>& result, int leftRemaining, int rightRemaining, string& str) {
        if (leftRemaining < 0 || rightRemaining < leftRemaining) return; // invalid state

        // Out of left and right parentheses
        if (!leftRemaining && !rightRemaining) {
            result.push_back(str);
            return;
        }

        str.push_back('('); // Add left and recurse
        addParen(result, leftRemaining - 1, rightRemaining, str);
        str.pop_back();
        str.push_back(')'); // Add right and recurse
        addParen(result, leftRemaining, rightRemaining - 1, str);
        str.pop_back();
    }
public:
    vector<string> generateParenthesis(int n) {
        string str; str.reserve(2 * n);
        vector<string> result;
        addParen(result, n, n, str);
        return result;
    }
};

void printSolution(vector<string> input)
{
    for (const string& item : input) cout << item << ", ";
    cout << endl;
}

int main()
{
	Solution solution;
	printSolution(solution.generateParenthesis(3));
	printSolution(solution.generateParenthesis(1));
	return 0;
}
