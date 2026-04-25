#include <iostream>
#include <numeric>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        const size_t numsLength = nums.size();
        const int expectedSum = (1 + numsLength) * numsLength / 2;
        unordered_set<int> uniqueNums(nums.begin(), nums.end());
        int uniqueSum = 0;
        for (const int num : uniqueNums) uniqueSum += num;
        const int sum = accumulate(nums.begin(), nums.end(), 0);
        return {sum - uniqueSum, expectedSum - uniqueSum};
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
	vector<int> nums1 = {1, 2, 2, 4};
    printVector(s.findErrorNums(nums1));
	vector<int> nums2 = {1, 1};
    printVector(s.findErrorNums(nums2));
	return 0;
}
