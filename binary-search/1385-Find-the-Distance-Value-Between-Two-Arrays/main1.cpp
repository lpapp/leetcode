#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int prefix[2202] = {}, res = 0;
        for (const int value : arr2) ++prefix[value + 1101];
        for (int index = 1; index < 2202; ++index) prefix[index] += prefix[index - 1];
        for (const int value : arr1) res += prefix[value + d + 1101] == prefix[value - d + 1100];
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> arr11 = {4, 5, 8};
    vector<int> arr12 = {10, 9, 1, 8};
    assert(s.findTheDistanceValue(arr11, arr12, 2) == 2);
    vector<int> arr21 = {1, 4, 2, 3};
    vector<int> arr22 = {-4, -3, 6, 10, 20, 30};
    assert(s.findTheDistanceValue(arr21, arr22, 3) == 2);
    vector<int> arr31 = {2, 1, 100, 3};
    vector<int> arr32 = {-5, -2, 10, -3, 7};
    assert(s.findTheDistanceValue(arr31, arr32, 6) == 1);
    return 0;
}
