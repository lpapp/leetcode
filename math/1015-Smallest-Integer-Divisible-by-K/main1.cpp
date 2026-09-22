#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if (!(k % 2) || !(k % 5)) return -1;
        for (int len = 1, rem = 1 % k; len <= k; ++len) {
            if (!rem) return len;
            rem = (rem * 10 + 1) % k;
        }
        return -1;      
    }
};

int main()
{
    Solution s;
    assert(s.smallestRepunitDivByK(1) == 1);
    assert(s.smallestRepunitDivByK(2) == -1);
    assert(s.smallestRepunitDivByK(3) == 3);
    return 0;
}
