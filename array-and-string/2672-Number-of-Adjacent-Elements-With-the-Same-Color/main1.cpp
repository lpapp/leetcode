#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int> colors(n, 0), res; res.reserve(queries.size());
        for (int count = 0; const vector<int>& query : queries) {
            const int index = query[0], newColor = query[1];
            if (colors[index]) {
                if (index > 0 && colors[index - 1] == colors[index]) --count;
                if (index < n - 1 && colors[index + 1] == colors[index]) --count;
            }
            if (index > 0 && colors[index - 1] == newColor) ++count;
            if (index < n - 1 && colors[index + 1] == newColor) ++count;
            colors[index] = newColor;
            res.push_back(count);
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> queries1 = {
        {0, 2},
        {1, 2},
        {3, 1},
        {1, 1},
        {2, 1}
    };
    vector<int> res1 = {0, 1, 1, 0, 2};
    assert(s.colorTheArray(4, queries1) == res1);
    vector<vector<int>> queries2 = {
        {0, 100000},
    };
    vector<int> res2 = {0};
    assert(s.colorTheArray(1, queries2) == res2);
    return 0;
}
