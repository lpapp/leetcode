#include <algorithm>
#include <cassert>
#include <numeric>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> res; res.reserve(m);
        for (int i = 0; i < m - 1; ++i) { res.emplace_back(n, '#'); res.back()[0] = '.'; }
        res.emplace_back(n, '.');
        return res;
    }
};

int main()
{
	Solution s;
    vector<string> res1 = {".##", "..."};
    assert(s.createGrid(2, 3) == res1);
    vector<string> res2 = {".##", ".##", "..."};
    assert(s.createGrid(3, 3) == res2);
    vector<string> res3 = {"...."};
    assert(s.createGrid(1, 4) == res3);
	return 0;
}
