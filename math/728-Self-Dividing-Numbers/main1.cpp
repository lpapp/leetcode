#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
    static bool isSelfDividing(int num) {
        for (int rem = num; rem; rem /= 10) {
            const int digit = rem % 10;
            if (!digit || num % digit) return false;
        }
        return true;
    }
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res; res.reserve(right - left + 1);
        for (int num = left; num <= right; ++num) if (isSelfDividing(num)) res.push_back(num);
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> res1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22};
    assert(s.selfDividingNumbers(1, 22) == res1);
    vector<int> res2 = {48, 55, 66, 77};
    assert(s.selfDividingNumbers(47, 85) == res2);
    return 0;
}
