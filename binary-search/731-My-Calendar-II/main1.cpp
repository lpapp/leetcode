#include <cassert>
#include <vector>

using namespace std;

class MyCalendarTwo {
      vector<pair<int, int>> single, dbl;
  public:
      bool book(int startTime, int endTime) {
          for (const auto& [dlo, dhi] : dbl) if (startTime < dhi && dlo < endTime) return false;
          for (const auto& [slo, shi] : single) {
              const int lo = max(startTime, slo), hi = min(endTime, shi);
              if (lo < hi) dbl.push_back({lo, hi});
          }
          single.push_back({startTime, endTime});
          return true;
      }
};

int main()
{
    MyCalendarTwo myCalendarTwo;
    assert(myCalendarTwo.book(10, 20));
    assert(myCalendarTwo.book(50, 60));
    assert(myCalendarTwo.book(10, 40));
    assert(!myCalendarTwo.book(5, 15));
    assert(myCalendarTwo.book(5, 10));
    assert(myCalendarTwo.book(25, 55));
    return 0;
}
