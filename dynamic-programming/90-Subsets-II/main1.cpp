#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    void depthFirstSearch(size_t index, vector<int>& tempSubset, vector<int>& nums, vector<vector<int>>& subsets) {
        subsets.push_back(tempSubset);

        for (size_t i = index; i < nums.size(); ++i) {
            if (i != index && nums[i] == nums[i - 1]) continue;
            tempSubset.push_back(nums[i]);
            depthFirstSearch(i + 1, tempSubset, nums, subsets);
            tempSubset.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<std::vector<int>> subsets;
        vector<int> tempSubset;
        depthFirstSearch(0, tempSubset, nums, subsets);
        return subsets;       
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
	vector<int> input1 = {1, 2, 2};
	printSolution(solution.subsetsWithDup(input1));

	vector<int> input2 = {0};
	printSolution(solution.subsetsWithDup(input2));
	return 0;
}
