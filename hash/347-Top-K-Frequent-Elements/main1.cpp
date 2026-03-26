#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        for (int num : nums) ++hash[num];
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        for (const auto& [number, count] : hash) {
            minHeap.push({count, number});
            if (static_cast<int>(minHeap.size()) > k) minHeap.pop();
        }
        vector<int> result;
        for (; !minHeap.empty(); minHeap.pop()) result.push_back(minHeap.top().second);
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
