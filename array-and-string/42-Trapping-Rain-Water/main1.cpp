#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left(n), right(n);
        left[0] = height[0], right[n - 1] = height[n - 1];
        for (int i = 1; i < n; ++i) { left[i] = max(left[i - 1], height[i]); right[n - i - 1] = max(right[n - i], height[n - i - 1]); }
        int res = 0;
        for (int i = 0; i < n; ++i) res += min(left[i], right[i]) - height[i];
        return res;
    }
};

int main()
{
	Solution s;
	vector<int> height1 = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << s.trap(height1) << endl;
	vector<int> height2 = {4, 2, 0, 3, 2, 5};
    cout << s.trap(height2) << endl;
	return 0;
}
