#include <iostream>
#include <vector>

using namespace std;

class Solution {
	void dfs(int number, vector<int>& combination, int n, int k, vector<vector<int>>& result) {
	    if (static_cast<int>(combination.size()) == k) { result.push_back(combination); return; }
	    if (number > n) return;
	    combination.push_back(number);
	    dfs(number + 1, combination, n, k, result);
	    combination.pop_back();
	    dfs(number + 1, combination, n, k, result);
	};
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> combination;
        dfs(1, combination, n, k, result);
        return result;
    }
};

void printVectorVector(const vector<vector<int>>& input)
{
    cout << "[";
    for (const vector<int>& v: input) {
        cout << "[";
        for (const int i: v) {
            cout << i << ",";
        }
        cout << "],";
    }
    cout << "]" << endl;
}

int main()
{
	Solution s;
    printVectorVector(s.combine(4, 2));
    printVectorVector(s.combine(1, 1));
	return 0;
}
