#include <cassert>
#include <cstdlib>
#include <string>

using namespace std;

class Solution {
public:
    int maxDistance(string moves) {
        int right = 0, up = 0, w = 0;
        for (const char move : moves) {
            if (move == 'U') ++up;
            else if (move == 'D') --up;
            else if (move == 'R') ++right;
            else if (move == 'L') --right;
            else ++w;
        }
        return abs(up) + abs(right) + w;
    }
};

int main()
{
    Solution s;
    assert(s.maxDistance("L_D_") == 4);
    assert(s.maxDistance("U_R") == 3);
    return 0;
}
