#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> result;
        for (size_t i = 0; i < nums.size(); i += 2) {
            int frequency = nums[i], value = nums[i + 1];
            for (int j = 0; j < frequency; j++) result.push_back(value);
        }
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
    vector<int> nums1 = {1, 2, 3, 4};
    printVector(s.decompressRLElist(nums1));
    vector<int> nums2 = {1, 1, 2, 3};
    printVector(s.decompressRLElist(nums2));
	return 0;
}
