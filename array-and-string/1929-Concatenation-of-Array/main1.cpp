#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        for (size_t i = 0, numsLength = nums.size(); i < numsLength; ++i) nums.push_back(nums[i]);
        return nums;       
    }
};

void printVector(vector<int> input)
{
    for (const int item : input) cout << item << ", ";
    cout << endl;
}

int main()
{
	Solution s;
	vector<int> nums1 = {1, 2, 1};
    printVector(s.getConcatenation(nums1));
	vector<int> nums2 = {1, 3, 2, 1};
    printVector(s.getConcatenation(nums2));
	return 0;
}
