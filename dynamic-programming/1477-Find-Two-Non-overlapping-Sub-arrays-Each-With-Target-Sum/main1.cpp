#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size(), INF = 1 << 30, res = INF;
        vector<int> best(n, INF);
        for (int r = 0, sum = 0, l = 0, minLen = INF; r < n; best[r++] = minLen) {
            sum += arr[r];
            while (sum > target) sum -= arr[l++];
            if (sum == target) {
                const int len = r - l + 1;
                if (l > 0 && best[l - 1] != INF) res = min(res, best[l - 1] + len);
                minLen = min(minLen, len);
            }
        }
        return res == INF ? -1 : res;
    }
};

int main()
{
    Solution s;
    vector<int> arr1 = {3, 2, 2, 4, 3};
    assert(s.minSumOfLengths(arr1, 3) == 2);
    vector<int> arr2 = {7, 3, 4, 7};
    assert(s.minSumOfLengths(arr2, 7) == 2);
    vector<int> arr3 = {4, 3, 2, 6, 2, 3, 4};
    assert(s.minSumOfLengths(arr3, 6) == -1);
    return 0;
}
