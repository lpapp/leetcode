#include <algorithm>
#include <cassert>

using namespace std;

class Solution {
public:
    int findKthNumber(int n, int k) {
        long long current = 1;
        for (long long remaining = k - 1; remaining > 0; ) {
            long long next = current + 1, count = 0;
            for (long long c = current; c <= n; next *= 10, c *= 10) count += min((long long)n - c + 1, next - c);
            if (remaining >= count) { remaining -= count; ++current; }
            else { --remaining; current *= 10; }
        }
        return (int)current;   
    }
};

int main()
{
    Solution s;
    assert(s.findKthNumber(13, 2) == 10);
    assert(s.findKthNumber(1, 1) == 1);
    return 0;
}
