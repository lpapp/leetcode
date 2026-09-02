#include <cassert>
#include <map>

using namespace std;

class MyCalendar {
    map<int, int> events;
public:
    bool book(int startTime, int endTime) {
        const auto it = events.upper_bound(startTime);
        if (it != events.end() && it->second < endTime) return false;
        events[endTime] = startTime;
        return true;
    }
};


int main()
{
    MyCalendar myCalendar;
    assert(myCalendar.book(10, 20));
    assert(!myCalendar.book(15, 25));
    assert(myCalendar.book(20, 30));
    return 0;
}
