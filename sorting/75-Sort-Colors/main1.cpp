#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        for (int left = -1, right = nums.size(), current = 0; current < right;) {
            if (!nums[current]) swap(nums[++left], nums[current++]);
            else if (nums[current] == 2) swap(nums[--right], nums[current]);
            else ++current;
        }       
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
    vector<int> nums1 = {2, 0, 2, 1, 1, 0};
    s.sortColors(nums1);
    printVector(nums1);
    vector<int> nums2 = {2, 0, 1};
    s.sortColors(nums2);
    printVector(nums2);
	return 0;
}
