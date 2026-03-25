#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> hash;
        for (const int num : nums1) ++hash[num];
        vector<int> result;
        for (const int num : nums2) if (hash[num]-- > 0) result.push_back(num);
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
    printVector(s.intersect(nums11, nums21));

    vector<int> nums12 = {4, 9, 5};
    vector<int> nums22 = {9, 4, 9, 8, 4};
    printVector(s.intersect(nums12, nums22));
	return 0;
}
