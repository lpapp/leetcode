#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return rec2[1] < rec1[3] && rec2[3] > rec1[1] && rec2[0] < rec1[2] && rec2[2] > rec1[0];
    }
};

int main()
{
    Solution s;
    vector<int> rec11 = {0, 0, 2, 2};
    vector<int> rec21 = {1, 1, 3, 3};
    assert(s.isRectangleOverlap(rec11, rec21));
    vector<int> rec12 = {0, 0, 1, 1};
    vector<int> rec22 = {1, 0, 2, 1};
    assert(!s.isRectangleOverlap(rec12, rec22));
    vector<int> rec13 = {0, 0, 1, 1};
    vector<int> rec23 = {2, 2, 3, 3};
    assert(!s.isRectangleOverlap(rec13, rec23));
    return 0;
}
