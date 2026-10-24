#include <cassert>
#include <string>

using namespace std;

class Solution {
    static int dayOfYear(const string& date) {
        static constexpr int prefix[12]{0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
        return prefix[(date[0] - '0') * 10 + date[1] - '0' - 1] + (date[3] - '0') *
 10 + date[4] - '0';
    }
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) { return max(0, dayOfYear(min(leaveAlice, leaveBob)) - dayOfYear(max(arriveAlice, arriveBob)) + 1); }
};

int main()
{
    Solution s;
    assert(s.countDaysTogether("08-15", "08-18", "08-16", "08-19") == 3);
    assert(s.countDaysTogether("10-01", "10-31", "11-01", "12-31") == 0);
    return 0;
}
