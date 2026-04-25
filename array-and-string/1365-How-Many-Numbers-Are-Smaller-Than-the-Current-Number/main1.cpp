#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> sortedArray = nums;
        sort(sortedArray.begin(), sortedArray.end());
        for (size_t i = 0; i < nums.size(); ++i) nums[i] = lower_bound(sortedArray.cbegin(), sortedArray.cend(), nums[i]) - sortedArray.cbegin();
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
	vector<int> nums1 = {8, 1, 2, 2, 3};
    printVector(s.smallerNumbersThanCurrent(nums1));
	vector<int> nums2 = {6, 5, 4, 8};
    printVector(s.smallerNumbersThanCurrent(nums2));
	vector<int> nums3 = {7, 7, 7, 7};
    printVector(s.smallerNumbersThanCurrent(nums3));
	return 0;
}
