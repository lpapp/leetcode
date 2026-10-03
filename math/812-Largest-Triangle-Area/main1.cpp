#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        long long best = 0;
        for (int i = 0, n = points.size(); i < n; ++i) for (int j = i + 1; j < n; ++j) for (int k = j + 1; k < n; ++k) {
            const int u1 = points[j][0] - points[i][0], v1 = points[j][1] - points[i][1], u2 = points[k][0] - points[i][0], v2 = points[k][1] - points[i][1];
            best = max(best, abs((long long)u1 * v2 - (long long)u2 * v1));
        }
        return best / 2.0;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> points1 = {{0, 0}, {0, 1}, {1, 0}, {0, 2}, {2, 0}};
    assert(s.largestTriangleArea(points1) == 2);
    vector<vector<int>> points2 = {{1, 0}, {0, 0}, {0, 1}};
    assert(s.largestTriangleArea(points2) == 0.5);
    return 0;
}
