#include <cassert>
#include <string>

using namespace std;

class Solution {
public:
    char findKthBit(int n, int k) {
        int flip = 0;
        for (int len = (1 << n) - 1; len > 1; len >>= 1) {
            const int mid = (len + 1) / 2;
            if (k == mid) return '0' + (1 ^ flip);
            if (k > mid) {
                k = len - k + 1;
                flip ^= 1;
            }
        }
        return '0' + flip;
    }
};

int main()
{
    Solution s;
    assert(s.findKthBit(3, 1) == '0');
    assert(s.findKthBit(4, 11) == '1');
    return 0;
}
