#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int freq[10] = {}, res = 0;
        for (const int digit : digits) ++freq[digit];
        for (int hundreds = 1; hundreds <= 9; ++hundreds) {
            if (!freq[hundreds]) continue;
            for (int tens = 0; tens <= 9; ++tens) {
                if (!freq[tens] || (tens == hundreds && freq[hundreds] < 2)) continue;
                for (int ones = 0; ones <= 8; ones += 2) {
                    const bool usedHundreds = ones == hundreds, usedTens = ones == tens;
                    if (freq[ones] && !(usedHundreds && usedTens && freq[ones] < 3) && !((usedHundreds || usedTens) && freq[ones] < 2)) ++res;
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> digits1 = {1, 2, 3, 4};
    assert(s.totalNumbers(digits1) == 12);
    vector<int> digits2 = {0, 2, 2};
    assert(s.totalNumbers(digits2) == 2);
    vector<int> digits3 = {6, 6, 6};
    assert(s.totalNumbers(digits3) == 1);
    vector<int> digits4 = {1, 3, 5};
    assert(s.totalNumbers(digits4) == 0);
    return 0;
}
