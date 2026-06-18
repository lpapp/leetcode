#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 1;
        for (int r = arr.size() - 2; l < r;) {
            int mid = l + (r - l) / 2;
            if (arr[mid] < arr[mid + 1]) l = mid + 1;
            else r = mid;
        }
        return l;
    }
};

int main()
{
    Solution s;
    vector<int> arr1 = {0, 1, 0};
    assert(s.peakIndexInMountainArray(arr1) == 1);
    vector<int> arr2 = {0, 2, 1, 0};
    assert(s.peakIndexInMountainArray(arr2) == 1);
    vector<int> arr3 = {0, 10, 5, 2};
    assert(s.peakIndexInMountainArray(arr3) == 1);
    return 0;
}
