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
        if (points.size() <= 2) return points.size();
        int res = 1;
        for (int i = 0, n = points.size(); i < n - 1; ++i) {
            unordered_map<string, int> hash;
            for (int j = i + 1; j < n; ++j) {
                int diffX = points[j][0] - points[i][0], diffY = points[j][1] - points[i][1], g = gcd(abs(diffX), abs(diffY));
                diffX /= g; diffY /= g;
                if (diffX < 0 || (diffX == 0 && diffY < 0)) { diffX = -diffX; diffY = -diffY; }
                string slope = to_string(diffX) + ":" + to_string(diffY);
                ++hash[slope];
                res = max(res, hash[slope] + 1);
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
