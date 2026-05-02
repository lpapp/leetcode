#include <array>
#include <cassert>

using namespace std;

class Solution {
    bool isGood(int number, array<int, 10>& hash) {
        int rotated = 0;
        for (int original = number, digitMultiplier = 1; original > 0; digitMultiplier *= 10, original /= 10) {
            int digit = original % 10;
            if (hash[digit] == -1) return false;
            rotated += hash[digit] * digitMultiplier;
        }
        return number != rotated;
    };
public:
    int rotatedDigits(int n) {
        array<int, 10> hash = {0, 1, 5, -1, -1, 2, 9, -1, 8, 6};
        int res = 0;
        for (int i = 1; i <= n; ++i) if (isGood(i, hash)) ++res;
        return res;
    }
};

int main()
{
	Solution s;
    assert(s.rotatedDigits(10) == 4);
    assert(!s.rotatedDigits(1));
    assert(s.rotatedDigits(2) == 1);
	return 0;
}
