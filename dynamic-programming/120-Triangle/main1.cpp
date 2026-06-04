#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for (int row = triangle.size() - 2; row >= 0; row--) for (int column = 0, n = triangle[row].size(); column < n; ++column) triangle[row][column] += min(triangle[row + 1][column], triangle[row + 1][column + 1]);
        return triangle[0][0];
    }
};

int main()
{
	Solution s;
    vector<vector<int>> triangle1 = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8,3}
    };
    assert(s.minimumTotal(triangle1) == 11);
    vector<vector<int>> triangle2 = {{-10}};
    assert(s.minimumTotal(triangle2) == -10);
	return 0;
}
