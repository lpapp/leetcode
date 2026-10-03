#include <cassert>
#include <cstdlib>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        long long areaA = (long long)(ax2 - ax1) * (ay2 - ay1), areaB = (long long)(bx2 - bx1) * (by2 - by1), overlapWidth = max(0, min(ax2, bx2) - max(ax1, bx1)), overlapHeight = max(0, min(ay2, by2) - max(ay1, by1));
        return (int)(areaA + areaB - overlapWidth * overlapHeight);
    }
};

int main()
{
    Solution s;
    assert(s.computeArea(-3, 0, 3, 4, 0, -1, 9, 2) == 45);
    assert(s.computeArea(-2, -2, 2, 2, -2, -2, 2, 2) == 16);
    return 0;
}
