#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> numToIndex;
        const int numsSize = nums.size();
        for (int i = 0; i < numsSize; ++i) {
            const int num = nums[i];
            const int complement = target - num;
            if (numToIndex.contains(complement)) return {numToIndex[complement], i};
            numToIndex[num] = i;
        }
        return {};       
    }
};

void printSolution(vector<int> input)
{
    for (const int& item : input) cout << item << ", ";
    cout << endl;
}

int main()
{
	Solution solution;

    vector<int> input1 = {2, 7, 11, 15};
	printSolution(solution.twoSum(input1, 9));

    vector<int> input2 = {3, 2, 4};
	printSolution(solution.twoSum(input2, 6));

    vector<int> input3 = {3, 3};
	printSolution(solution.twoSum(input3, 6));

	return 0;
}
