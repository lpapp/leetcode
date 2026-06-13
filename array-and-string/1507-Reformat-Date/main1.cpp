#include <cassert>
#include <format>
#include <string>

using namespace std;

class Solution {
public:
    string reformatDate(string date) {
        static constexpr array<string_view, 12> m = {"Jan","Feb","Mar","Apr","May","Jun", "Jul","Aug","Sep","Oct","Nov","Dec"};
        const int day = stoi(date), sp = date.find(' ');
        string_view mon(&date[sp + 1], 3);
        const int month = find(m.cbegin(), m.cend(), mon) - m.cbegin() + 1;
        const string year(date, sp + 5, 4);
        return format("{}-{:02d}-{:02d}", year, month, day);   
    }
};

int main()
{
    Solution s;
    assert(s.reformatDate("20th Oct 2052") == "2052-10-20");
    assert(s.reformatDate("6th Jun 1933") == "1933-06-06");
    assert(s.reformatDate("26th May 1960") == "1960-05-26");
    return 0;
}
