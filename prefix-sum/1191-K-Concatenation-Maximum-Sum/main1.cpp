#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        long long sum = 0, maxPre = 0, minPre = 0, maxSub = 0, MOD = 1'000'000'007;
        for (const int num : arr) {
            sum += num;
            maxPre = max(maxPre, sum);
            minPre = min(minPre, sum);
            maxSub = max(maxSub, sum - minPre);
        }
        if (k == 1) return static_cast<int>(maxSub % MOD);
        const long long maxSuf = sum - minPre;
        long long res = max(maxSub, maxPre + maxSuf);
        if (sum > 0) res = max(res, static_cast<long long>(k - 2) * sum + maxPre + maxSuf);
        return static_cast<int>(res % MOD);
    }
};

int main()
{
    Solution s;
    vector<int> arr1 = {1, 2};
    assert(s.kConcatenationMaxSum(arr1, 3) == 9);
    vector<int> arr2 = {1, -2, 1};
    assert(s.kConcatenationMaxSum(arr2, 5) == 2);
    vector<int> arr3 = {-1, -2};
    assert(s.kConcatenationMaxSum(arr3, 7) == 0);
    return 0;
}
