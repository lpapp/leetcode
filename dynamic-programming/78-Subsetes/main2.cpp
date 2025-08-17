#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector<int> convertIntToVector(int x, vector<int>& nums) {
        vector<int> subset;
        for (int k = x, index = 0; k > 0; ++index, k >>=1) {
            if ((k&1) == 1) subset.push_back(nums[index]);
        }
        return subset;
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> allSubsets;
        int max = 1 << nums.size();
        for (int k = 0; k < max; ++k) {
            vector<int> subset = convertIntToVector(k, nums);
            allSubsets.push_back(subset);
        }
        return allSubsets;
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
	printSolution(solution.subsets(input1));

	vector<int> input2 = {0};
	printSolution(solution.subsets(input2));
	return 0;
}
