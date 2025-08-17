#include <iostream>
#include <vector>

using namespace std;

class Solution {
	void getPerms(vector<int>& prefix, vector<int>& remainder, vector<vector<int>>& result) {
		const size_t len = remainder.size();
		if (!len) result.push_back(prefix);

		for (size_t i = 0; i < len; ++i) {
			vector<int>::const_iterator remainderBegin = remainder.begin();
			vector<int> beforeAfter(remainderBegin, remainderBegin + i);
			beforeAfter.insert(beforeAfter.end(), remainderBegin + i + 1, remainderBegin + len);
			const int item = remainder[i];
			prefix.push_back(item);
			getPerms(prefix, beforeAfter, result);
			prefix.pop_back();
		}
	}
public:
    vector<vector<int>> permute(vector<int>& nums) {
    	vector<vector<int>> result;
		vector<int> prefix = {};
		getPerms(prefix, nums, result);
		return result;
    }
};

void printSolution(vector<vector<int>> input)
{
    cout << "[";
    for (const vector<int>& vectorItem : input) {
        cout << "[";
        for (const int item : vectorItem) cout << item << ", ";
        cout << "]";
    }
    cout << "]";
    cout << endl;
}

int main()
{
	Solution solution;

	vector<int> input1 = {1, 2, 3};
	printSolution(solution.permute(input1));

	vector<int> input2 = {0, 1};
	printSolution(solution.permute(input2));

	vector<int> input3 = {1};
	printSolution(solution.permute(input3));

	return 0;
}
