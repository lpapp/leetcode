#include <iostream>
#include <vector>

using namespace std;

class Solution {
	vector<vector<int>> getSubsets(vector<int>& nums, size_t index) {
		vector<vector<int>> allSubsets;
		if (nums.size() == index) {
			allSubsets.push_back({});
		} else {
			allSubsets = getSubsets(nums, index + 1);
			int item = nums[index];
			vector<vector<int>> moreSubsets;
			for (const vector<int>& subset : allSubsets) {
				vector<int> newSubset;
				newSubset.insert(newSubset.end(), subset.begin(), subset.end());	
				newSubset.push_back(item);
				moreSubsets.push_back(newSubset);
			}
			allSubsets.insert(allSubsets.end(), moreSubsets.begin(), moreSubsets.end());
		}

		return allSubsets;
	}

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        return getSubsets(nums, 0);
    }
};

int main()
{
	Solution solution;
	vector<int> input1 = {1, 2, 3};
	solution.subsets(input1);

	vector<int> input2 = {0};
	solution.subsets(input2);
	return 0;
}
