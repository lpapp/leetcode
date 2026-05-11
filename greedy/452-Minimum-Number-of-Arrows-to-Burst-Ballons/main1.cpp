#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b) { return a[1] < b[1]; });
        int res = 0, arrow = -1;
        for (const vector<int>& balloon : points) { if (balloon[0] > arrow) { ++res; arrow = balloon[1]; } }
        return res;
    }
};

int main()
{
	Solution s;
    vector<vector<int>> points1 = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
    assert(s.findMinArrowShots(points1) == 2);
    vector<vector<int>> points2 = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
    assert(s.findMinArrowShots(points2) == 4);
	return 0;
}
