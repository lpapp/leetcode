#include <cassert>
#include <cmath>

using namespace std;

class Solution {
public:
    int pivotInteger(int n) {
        int t = n * (n + 1) / 2, x = sqrt(t);
        return x * x == t ? x : -1;
    }
};

int main()
{
    Solution s;
    assert(s.pivotInteger(8) == 6);
    assert(s.pivotInteger(1) == 1);
    assert(s.pivotInteger(4) == -1);
    return 0;
}
