#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
    static array<bool, 101> sieve() {
        array<bool, 101> p{};
        p.fill(true);
        p[0] = p[1] = false;
        for (int i = 2; i * i <= 100; ++i) if (p[i]) for (int j = i * i; j <= 100; j += i) p[j] = false;
        return p;
    }
public:
    int maximumPrimeDifference(vector<int>& nums) {
        static const array<bool, 101> isPrime = sieve();
        int first = 0;
        while (!isPrime[nums[first]]) ++first;
        int last = static_cast<int>(nums.size()) - 1;
        while (!isPrime[nums[last]]) --last;
        return last - first;
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {4, 2, 9, 5, 3};
    assert(s.maximumPrimeDifference(nums1) == 3);
    vector<int> nums2 = {4, 8, 2, 8};
    assert(s.maximumPrimeDifference(nums2) == 0);
    return 0;
}
