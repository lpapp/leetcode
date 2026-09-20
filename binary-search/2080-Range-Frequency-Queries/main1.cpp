#include <algorithm>
#include <cassert>
#include <numeric>
#include <vector>

using namespace std;

class RangeFreqQuery {
    vector<vector<int>> pos;
public:
    RangeFreqQuery(vector<int>& arr) : pos(10001) { for (int i = 0, n = arr.size(); i < n; ++i) pos[arr[i]].push_back(i); }
    int query(int left, int right, int value) { const vector<int>& idx = pos[value]; return ranges::upper_bound(idx, right) - ranges::lower_bound(idx, left); }
};

int main()
{
    vector<int> arr1 = {12, 33, 4, 56, 22, 2, 34, 33, 22, 12, 34, 56};
    RangeFreqQuery rangeFreqQuery(arr1);
    assert(rangeFreqQuery.query(1, 2, 4) == 1);
    assert(rangeFreqQuery.query(0, 11, 33) == 2);
    return 0;
}
