#include <cassert>
#include <vector>

using namespace std;

class NumArray {
    int n;
    vector<int> bit, nums;
    void add(int i, int delta) { for (++i; i <= n; i += i & -i) bit[i] += delta; }
    int prefixSum(int i) const { int s = 0; for (++i; i > 0; i -= i & -i) s += bit[i]; return s; }
public:
    NumArray(vector<int>& nums) : n(nums.size()), bit(n + 1), nums(nums) {
        for (int i = 0; i < n; ++i) bit[i + 1] = nums[i];
        for (int i = 1; i <= n; ++i) {
            const int p = i + (i & -i);
            if (p <= n) bit[p] += bit[i];
        }
    }
    void update(int index, int val) {
        add(index, val - nums[index]);
        nums[index] = val;
    }
    int sumRange(int left, int right) const { return prefixSum(right) - (left ? prefixSum(left - 1) : 0); }
};

int main()
{
    vector<int> nums1 = {1, 3, 5};
    NumArray* numArray = new NumArray(nums1);
    assert(numArray->sumRange(0, 2) == 9);
    numArray->update(1, 2);
    assert(numArray->sumRange(0, 2) == 8);
    return 0;
}
