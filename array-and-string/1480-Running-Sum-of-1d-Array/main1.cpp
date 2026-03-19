#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for (size_t i = 1; i < nums.size(); ++i) nums[i] += nums[i - 1];
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
    vector<int> nums1 = {1, 2, 3, 4};
    printVector(s.runningSum(nums1));
    vector<int> nums2 = {1, 1, 1, 1, 1};
    printVector(s.runningSum(nums2));
    vector<int> nums3 = {3, 1, 2, 10, 1};
    printVector(s.runningSum(nums3));
	return 0;
}
