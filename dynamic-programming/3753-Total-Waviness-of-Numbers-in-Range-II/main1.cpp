#include <cassert>
#include <cstring>
#include <string>

using namespace std;

class Solution {
    inline static long long memo[16][2][11][11];
    inline static long long countMemo[16][2][11][11];
    static pair<long long, long long> dp(const string& digits, int position, int tight, int lastDigit, int secondLastDigit) {
        if (position == (int)digits.size()) return {0, 1};
        long long& cachedSum = memo[position][tight][lastDigit][secondLastDigit];
        long long& cachedCount = countMemo[position][tight][lastDigit][secondLastDigit];
        if (cachedSum != -1) return {cachedSum, cachedCount};
        const int limit = tight ? digits[position] - '0' : 9;
        long long totalSum = 0, totalCount = 0;
        for (int digit = 0; digit <= limit; ++digit) {
            const int newTight = tight && (digit == limit);
            if (lastDigit == 10 && digit == 0) {
                auto [sum, count] = dp(digits, position + 1, newTight, 10, 10);
                totalSum += sum;
                totalCount += count;
            } else {
                long long waviness = (lastDigit < 10 && secondLastDigit < 10 &&
                    ((lastDigit > secondLastDigit && lastDigit > digit) ||
                     (lastDigit < secondLastDigit && lastDigit < digit)));
                auto [sum, count] = dp(digits, position + 1, newTight, digit, lastDigit);
                totalSum += waviness * count + sum;
                totalCount += count;
            }
        }
        cachedSum = totalSum;
        cachedCount = totalCount;
        return {totalSum, totalCount};
    }
    static long long solve(const string& digits) {
        memset(memo, -1, sizeof(memo));
        memset(countMemo, -1, sizeof(countMemo));
        return dp(digits, 0, 1, 10, 10).first;
    }
public:
    long long totalWaviness(long long num1, long long num2) {
        return solve(to_string(num2)) - solve(to_string(num1 - 1));
    }
};

int main()
{
	Solution s;
    assert(s.totalWaviness(120, 130) == 3);
    assert(s.totalWaviness(198, 202) == 3);
    assert(s.totalWaviness(4848, 4848) == 2);
	return 0;
}
