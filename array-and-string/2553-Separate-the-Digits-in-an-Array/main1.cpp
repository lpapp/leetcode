#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> res;
        for (int number : nums) {
            vector<int> digits;
            for (; number > 0; digits.push_back(number % 10), number /= 10);
            for (; !digits.empty(); res.push_back(digits.back()), digits.pop_back());
        }
        return res;
    }
};

int main()
{
	Solution s;
    vector<int> nums1 = {13, 25, 83, 77};
    vector<int> res1 = {1, 3, 2, 5, 8, 3, 7, 7};
    assert(s.separateDigits(nums1) == res1);
    vector<int> nums2 = {7, 1, 3, 9};
    vector<int> res2 = {7, 1, 3, 9};
    assert(s.separateDigits(nums2) == res2);
	return 0;
}
