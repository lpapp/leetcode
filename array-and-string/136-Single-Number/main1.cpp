#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int num : nums) result ^= num;
        return result;       
    }
};

int main()
{
	Solution s;
    vector<int> nums1 = {2, 2, 1};
    cout << s.singleNumber(nums1) << endl;
    vector<int> nums2 = {4, 1, 2, 1, 2};
    cout << s.singleNumber(nums2) << endl;
    vector<int> nums3 = {1};
    cout << s.singleNumber(nums3) << endl;
	return 0;
}
