#include <cassert>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        constexpr int LEFT = 0b0111100000, RIGHT = 0b0000011110, MID = 0b0001111000;
        unordered_map<int, int> rows;
        for (const vector<int>& r : reservedSeats) rows[r[0]] |= 1 << (10 - r[1]);
        int res = (n - static_cast<int>(rows.size())) * 2;
        for (const auto [_, mask] : rows) {
            const bool l = !(mask & LEFT), r = !(mask & RIGHT), m = !(mask & MID);
            if (l && r) res += 2;
            else if (l || r || m) ++res;
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> reservedSeats1 = {{1, 2}, {1, 3}, {1, 8}, {2, 6}, {3, 1}, {3, 10}};
    assert(s.maxNumberOfFamilies(3, reservedSeats1) == 4);
    vector<vector<int>> reservedSeats2 = {{2, 1}, {1, 8}, {2, 6}};
    assert(s.maxNumberOfFamilies(2, reservedSeats2) == 2);
    vector<vector<int>> reservedSeats3 = {{4, 3}, {1, 4}, {4, 6}, {1, 7}};
    assert(s.maxNumberOfFamilies(4, reservedSeats3) == 4);
    return 0;
}
