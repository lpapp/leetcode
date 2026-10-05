#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        int sz = 1 << n;
        vector<int> res(sz);
        for (int i = 0; i < sz; ++i) res[i] = i ^ (i >> 1);
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> res1 = {0, 1, 3, 2};
    assert(s.grayCode(2) == res1);
    vector<int> res2 = {0, 1};
    assert(s.grayCode(1) == res2);
    return 0;
}
