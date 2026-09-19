#include <algorithm>
#include <cassert>

using namespace std;

class Solution {
    static int distToRange(int lo, int hi, int p) { return p < lo ? lo - p : p > hi ? p - hi : 0; }
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        const int dx = distToRange(x1, x2, xCenter), dy = distToRange(y1, y2, yCenter);
        return dx * dx + dy * dy <= radius * radius;
    }
};

int main()
{
    Solution s;
    assert(s.checkOverlap(1, 0, 0, 1, -1, 3, 1));
    assert(!s.checkOverlap(1, 1, 1, 1, -3, 2, -1));
    return 0;
}
