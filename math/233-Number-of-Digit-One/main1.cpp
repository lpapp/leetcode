#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        long long res = 0;
        for (long long base = 1; base <= n; base *= 10) {
            long long high = n / (base * 10), cur = (n / base) % 10, low = n % base;
            res += high * base;
            if (cur > 1) res += base;
            else if (cur == 1) res += low + 1;
        }
        return (int)res;
    }
};

int main()
{
    Solution s;
    assert(s.countDigitOne(13) == 6);
    assert(s.countDigitOne(0) == 0);
    return 0;
}
