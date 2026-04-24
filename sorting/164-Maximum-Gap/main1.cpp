#include <algorithm>
#include <iostream>
#include <numeric>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        const int numsLength = nums.size();
        if (numsLength < 2) return 0;
        int minVal = numeric_limits<int>::max(), maxVal = numeric_limits<int>::min();
        for (const int num : nums) { minVal = min(minVal, num); maxVal = max(maxVal, num); }
        const int bucketSize = max(1, (maxVal - minVal) / (numsLength - 1)), bucketCount = (maxVal - minVal) / bucketSize + 1;
        vector<pair<int, int>> buckets(bucketCount, {numeric_limits<int>::max(), numeric_limits<int>::min()});
        for (const int num : nums) {
            const int bucketIndex = (num - minVal) / bucketSize;
            buckets[bucketIndex].first = min(buckets[bucketIndex].first, num);
            buckets[bucketIndex].second = max(buckets[bucketIndex].second, num);
        }
        int result = 0, prev = numeric_limits<int>::max();
        for (const auto [bucketMin, bucketMax] : buckets) {
            if (bucketMin > bucketMax) continue;
            result = max(result, bucketMin - prev);
            prev = bucketMax;
        }
        return result;
    }
};

int main()
{
	Solution s;
    vector<int> nums1 = {3, 6, 9, 1};
    cout << s.maximumGap(nums1) << endl;
    vector<int> nums2 = {10};
    cout << s.maximumGap(nums2) << endl;
	return 0;
}
