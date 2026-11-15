#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        constexpr int MOD = 1'000'000'007;
        long long even = 1, odd = 0;
        for (int parity = 0; const int num : arr) { parity ^= num & 1; ++(parity ? odd : even); }
        return even * odd % MOD;   
    }
};

int main()
{
    Solution s;
    vector<int> arr1 = {1, 3, 5};
    assert(s.numOfSubarrays(arr1) == 4);
    vector<int> arr2 = {2, 4, 6};
    assert(s.numOfSubarrays(arr2) == 0);
    vector<int> arr3 = {1, 2, 3, 4, 5, 6, 7};
    assert(s.numOfSubarrays(arr3) == 16);
    return 0;
}
