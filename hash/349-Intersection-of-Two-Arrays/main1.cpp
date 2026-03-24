#include <array>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        array<bool, 1001> hash;
        for (int num : nums1) hash[num] = true;
        vector<int> result;
        for (int num : nums2) if (hash[num]) { result.push_back(num); hash[num] = false; }
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
    vector<int> nums11 = {1, 2, 2, 1};
    vector<int> nums21 = {2, 2};
    printVector(s.intersection(nums11, nums21));

    vector<int> nums12 = {4, 9, 5};
    vector<int> nums22 = {9, 4, 9, 8, 4};
    printVector(s.intersection(nums12, nums22));
	return 0;
}
