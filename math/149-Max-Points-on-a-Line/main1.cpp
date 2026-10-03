#include <cassert>
#include <cstdlib>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        const int n = points.size();
        if (n <= 2) return n;
        int res = 1;
        for (int i = 0; i < n - 1; ++i) {
            unordered_map<long long, int> slopeCount;
            for (int j = i + 1; j < n; ++j) {
                long long dx = points[j][0] - points[i][0], dy = points[j][1] - points[i][1], g = gcd(dx, dy);
                dx /= g; dy /= g;
                if (dx < 0 || (dx == 0 && dy < 0)) { dx = -dx; dy = -dy; }
                res = max(res, ++slopeCount[dx * 20001 + dy] + 1);
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> points1 = {{1, 1}, {2, 2}, {3, 3}};
    assert(s.maxPoints(points1) == 3);
    vector<vector<int>> points2 = {{1, 1}, {3, 2}, {5, 3}, {4, 1}, {2, 3}, {1, 4}};
    assert(s.maxPoints(points2) == 4);
    return 0;
}
