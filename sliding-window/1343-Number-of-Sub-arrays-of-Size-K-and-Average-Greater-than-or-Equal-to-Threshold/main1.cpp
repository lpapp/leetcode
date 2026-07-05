#include <cassert>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        const int target = k * threshold;
        int sum = reduce(arr.cbegin(), arr.cbegin() + k, 0);
        int res = sum >= target;
        for (int i = k, n = arr.size(); i < n; ++i) {
            sum += arr[i] - arr[i - k];
            res += sum >= target;
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> arr1 = {2, 2, 2, 2, 5, 5, 5, 8};
    assert(s.numOfSubarrays(arr1, 3, 4) == 3);
    vector<int> arr2 = {11, 13, 17, 23, 29, 31, 7, 5, 2, 3};
    assert(s.numOfSubarrays(arr2, 3, 5) == 6);
    return 0;
}
