#include <algorithm>
#include <cassert>
#include <cstdlib>

using namespace std;

class Solution {
public:
    double angleClock(int hour, int minutes) {
        const double diff = abs(30.0 * (hour % 12) + 0.5 * minutes - 6.0 * minutes);
        return min(diff, 360 - diff);
    }
};

int main()
{
	Solution s;
    assert(s.angleClock(12, 30) == 165);
    assert(s.angleClock(3, 30) == 75);
    assert(s.angleClock(3, 15) == 7.5);
	return 0;
}
