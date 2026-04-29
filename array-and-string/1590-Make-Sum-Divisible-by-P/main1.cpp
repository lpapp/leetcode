#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int remainder = 0;
        for (const int num : nums) remainder = (remainder + num) % p;
        if (!remainder) return 0;
        unordered_map<int, int> hash{{0, -1}};
        int numsLength = nums.size(), result = numsLength;
        for (int i = 0, currentRemainder = 0; i < numsLength; ++i) {
            currentRemainder = (currentRemainder + nums[i]) % p;
            const int targetRemainder = (currentRemainder - remainder + p) % p;
            if (hash.contains(targetRemainder)) result = min(result, i - hash[targetRemainder]);
            hash[currentRemainder] = i;
        }
        return result == numsLength ? -1 : result;
    }
};

int main()
{
	Solution s;
    vector<int> nums1 = {3, 1, 4, 2};
    cout << s.minSubarray(nums1, 6) << endl;
    vector<int> nums2 = {6, 3, 5, 2};
    cout << s.minSubarray(nums2, 9) << endl;
    vector<int> nums3 = {1, 2, 3};
    cout << s.minSubarray(nums3, 3) << endl;
	return 0;
}
