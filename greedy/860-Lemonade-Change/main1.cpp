#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for (const int bill : bills) {
            if (bill == 5) ++five;
            else if (bill == 10) { ++ten; --five; }
            else { if (ten > 0) { --ten; --five; } else five -= 3; }
            if (five < 0) return false;
        }
        return true;
    }
};

int main()
{
    Solution s;
    vector<int> bills1 = {5, 5, 5, 10, 20};
    assert(s.lemonadeChange(bills1));
    vector<int> bills2 = {5, 5, 10, 10, 20};
    assert(!s.lemonadeChange(bills2));
    return 0;
}
