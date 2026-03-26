#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> hash;
        for (const int num1 : nums1) for (const int num2 : nums2) ++hash[num1 + num2];
        int result = 0;
        for (const int num3 : nums3) for (const int num4 : nums4) result += hash[-(num3 + num4)];
        return result;
    }
};

int main()
{
	Solution s;
    vector<int> nums11 = {1, 2};
    vector<int> nums21 = {-2, -1};
    vector<int> nums31 = {-1, 2};
    vector<int> nums41 = {0, 2};
    cout << s.fourSumCount(nums11, nums21, nums31, nums41) << endl;

    vector<int> nums12 = {0};
    vector<int> nums22 = {0};
    vector<int> nums32 = {0};
    vector<int> nums42 = {0};
    cout << s.fourSumCount(nums12, nums22, nums32, nums42) << endl;
	return 0;
}
