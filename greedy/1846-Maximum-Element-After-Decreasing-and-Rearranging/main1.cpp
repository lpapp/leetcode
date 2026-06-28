#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        ranges::sort(arr);
        int res = 0;
        for (const int num : arr) res = min(res + 1, num);
        return res;      
    }
};

int main()
{
    Solution s;
    vector<int> arr1 = {2, 2, 1, 2, 1};
    assert(s.maximumElementAfterDecrementingAndRearranging(arr1) == 2);
    vector<int> arr2 = {100, 1, 1000};
    assert(s.maximumElementAfterDecrementingAndRearranging(arr2) == 3);
    vector<int> arr3 = {1, 2, 3, 4, 5};
    assert(s.maximumElementAfterDecrementingAndRearranging(arr3) == 5);
    return 0;
}
