#include <algorithm>
#include <cassert>
#include <numeric>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size(), size = 2 * n - 1, best = 0;
        vector<pair<int,int>> ones1, ones2;
        for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
            if (img1[i][j]) ones1.emplace_back(i, j);
            if (img2[i][j]) ones2.emplace_back(i, j);
        }
        vector<int> cnt(size * size, 0);
        for (pair<int,int>& p1 : ones1) for (pair<int,int>& p2 : ones2) {
            const int dr = p1.first - p2.first + n - 1, dc = p1.second - p2.second + n - 1;
            best = max(best, ++cnt[dr * size + dc]);
        }
        return best;      
    }
};

int main()
{
    Solution s;
    vector<vector<int>> img11 = {{1, 1, 0}, {0, 1, 0}, {0, 1, 0}};
    vector<vector<int>> img21 = {{0, 0, 0}, {0, 1, 1}, {0, 0, 1}};
    assert(s.largestOverlap(img11, img21) == 3);
    vector<vector<int>> img12 = {{1}};
    vector<vector<int>> img22 = {{1}};
    assert(s.largestOverlap(img12, img22) == 1);
    vector<vector<int>> img13 = {{0}};
    vector<vector<int>> img23 = {{0}};
    assert(s.largestOverlap(img13, img23) == 0);
    return 0;
}
