#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
		vector<int> result;
        for (size_t i = 0; i < n; ++i) { result.push_back(nums[i]); result.push_back(nums[i + n]); }
        return result;
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
	vector<int> nums1 = {2, 5, 1, 3, 4, 7};
    printVector(s.shuffle(nums1, 3));
	vector<int> nums2 = {1, 2, 3, 4, 4, 3, 2, 1};
    printVector(s.shuffle(nums2, 4));
	vector<int> nums3 = {1, 1, 2, 2};
    printVector(s.shuffle(nums3, 2));
	return 0;
}
