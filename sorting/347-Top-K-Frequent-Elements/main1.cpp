#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        for (const int num : nums) ++counts[num];
        vector<vector<int>> frequencies(nums.size() + 1);
        for (const auto& [num, frequency] : counts) frequencies[frequency].push_back(num);
        vector<int> result;
        for (int i = frequencies.size() - 1; i > 0; --i) {
            for (const int num : frequencies[i]) {
                result.push_back(num);
                if (result.size() == k) return result;
            }
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
    vector<int> nums1 = {1, 1, 1, 2, 2, 3};
    printVector(s.topKFrequent(nums1, 2));
    vector<int> nums2 = {1};
    printVector(s.topKFrequent(nums2, 1));
    vector<int> nums3 = {1, 2, 1, 2, 1, 2, 3, 1, 3, 2};
    printVector(s.topKFrequent(nums3, 2));
	return 0;
}
