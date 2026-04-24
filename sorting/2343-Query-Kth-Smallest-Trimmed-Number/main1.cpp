#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        const size_t numsLength = nums.size();
        vector<pair<string, int>> trimmed(numsLength);
        vector<int> result;
        for (auto& query : queries) {
            const int k = query[0], length = query[1];
            for (size_t i = 0; i < numsLength; ++i) {
                string trim = nums[i].substr(nums[i].size() - length);
                trimmed[i] = {trim, i};
            }
            sort(trimmed.begin(), trimmed.end());
            result.push_back(trimmed[k - 1].second);
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
    vector<string> nums1 = {"102", "473", "251", "814"};
	vector<vector<int>> queries1 = {{1, 1}, {2, 3}, {4, 2}, {1, 2}};
    printVector(s.smallestTrimmedNumbers(nums1, queries1));
    vector<string> nums2 = {"24", "37", "96", "04"};
	vector<vector<int>> queries2 = {{2, 1}, {2, 2}};
    printVector(s.smallestTrimmedNumbers(nums2, queries2));
	return 0;
}
