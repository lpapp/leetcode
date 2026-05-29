#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        nth_element(points.begin(), points.begin() + k, points.end(), [](const vector<int>& a, const vector<int>& b) { return a[0]*a[0] + a[1]*a[1] < b[0]*b[0] + b[1]*b[1]; });
        points.resize(k);
        return points;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> points1 = {{1, 3}, {-2, 2}};
    vector<vector<int>> res1 = {{-2, 2}};
    assert(s.kClosest(points1, 1) == res1);
    vector<vector<int>> points2 = {{3, 3}, {5, -1}, {-2, 4}};
    vector<vector<int>> res2 = {{3, 3}, {-2, 4}};
    assert(s.kClosest(points2, 2) == res2);
    return 0;
}
