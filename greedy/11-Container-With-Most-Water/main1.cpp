#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        for (int left = 0, right = height.size() - 1; left < right;) {
            res = max(res, min(height[left], height[right]) * (right - left));
            if (height[left] < height[right]) ++left;
            else --right;
        }
        return res;
    }
};

int main()
{
	Solution s;
    vector<int> height1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    assert(s.maxArea(height1) == 49);
    vector<int> height2 = {1, 1};
    assert(s.maxArea(height2) == 1);
	return 0;
}
