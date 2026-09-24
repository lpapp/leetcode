#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);
        for (int i = 0; i < numRows; ++i) {
            res[i].assign(i + 1, 1);
            for (int j = 1; j < i; ++j) res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> res1 = {{1}, {1, 1}, {1, 2, 1}, {1, 3, 3, 1}, {1, 4, 6, 4, 1}};
    assert(s.generate(5) == res1);
    vector<vector<int>> res2 = {{1}};
    assert(s.generate(1) == res2);
    return 0;
}
