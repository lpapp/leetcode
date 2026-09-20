#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        const auto [mn, mx] = ranges::minmax(arr);
        if (mn == mx) return true;
        int n = arr.size();
        if ((mx - mn) % (n - 1)) return false;
        vector<char> seen(n, 0);
        for (const int d = (mx - mn) / (n - 1); const int v : arr) {
            const int off = v - mn;
            if (off % d) return false;
            const int k = off / d;
            if (k >= n || seen[k]) return false;
            seen[k] = 1;
        }
        return true; 
    }
};

int main()
{
    Solution s;
    vector<int> arr1 = {3, 5, 1};
    assert(s.canMakeArithmeticProgression(arr1));
    vector<int> arr2 = {1, 2, 4};
    assert(!s.canMakeArithmeticProgression(arr2));
    return 0;
}
