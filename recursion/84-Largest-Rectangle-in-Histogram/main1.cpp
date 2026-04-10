#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int result = 0;
        const size_t heightsLength = heights.size();
        stack<int> s;
        vector<int> left(heightsLength, -1), right(heightsLength, heightsLength);
        for (size_t i = 0; i < heightsLength; ++i) {
            for (; !s.empty() && heights[s.top()] >= heights[i]; s.pop()) right[s.top()] = i;
            if (!s.empty()) left[i] = s.top();
            s.push(i);
        }
        for (size_t i = 0; i < heightsLength; ++i) result = max(result, heights[i] * (right[i] - left[i] - 1));
        return result;
    }
};

int main()
{
	Solution s;
	vector<int> heights1 = {2, 1, 5, 6, 2, 3};
	cout << s.largestRectangleArea(heights1) << endl;
	vector<int> heights2 = {2, 4};
	cout << s.largestRectangleArea(heights2) << endl;
	return 0;
}
