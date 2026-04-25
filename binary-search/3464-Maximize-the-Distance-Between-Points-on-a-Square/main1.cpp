#include <algorithm>
#include <array>
#include <deque>
#include <iostream>
#include <vector>

using namespace std;

// Binary search on answer + greedy validation
// Time complexity: O(N * K * log(N) * log(side))
// Space complexity: O(N)
// N: number of points, K: number of points to select

class Solution {
	bool check(const vector<long long>& doubled, int n, long long perim, int k, long long d) {
	    deque<array<long long, 3>> dq;
	    dq.push_back({doubled[0], doubled[0], 1});
	    int maxLen = 1;
	    for (int i = 1; i < 2 * n; ++i) {
	        const long long cur = doubled[i];
	        long long bestStart = cur;
	        int bestLen = 1;
	        while (!dq.empty() && cur - dq.front()[1] >= d) {
	            if (cur - dq.front()[0] >= d
	                && dq.front()[0] + perim - cur >= d
	                && dq.front()[2] + 1 >= bestLen) {
	                bestStart = dq.front()[0];
	                bestLen = dq.front()[2] + 1;
	                maxLen = max(maxLen, bestLen);
	            }
	            dq.pop_front();
	        }
	        dq.push_back({bestStart, cur, bestLen});
	    }
	
	    return maxLen >= k;
	}
public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        const int n = points.size();
        const long long perim = 4LL * side;
        vector<long long> pos(n);
        for (int i = 0; i < n; ++i) {
            const long long x = points[i][0], y = points[i][1];
            if (y == 0) pos[i] = x;
            else if (x == side) pos[i] = side + y;
            else if (y == side) pos[i] = 3LL * side - x;
            else pos[i] = 4LL * side - y;
        }
        sort(pos.begin(), pos.end());
        vector<long long> doubled(2 * n);
        for (int i = 0; i < n; ++i) {
            doubled[i] = pos[i];
            doubled[i + n] = pos[i] + perim;
        }
        long long left = 0, right = side;
        while (left < right) {
            const long long mid = left + ((right - left + 1) >> 1);
            if (check(doubled, n, perim, k, mid)) left = mid;
            else right = mid - 1;
        }
        return left;
    }
};

int main()
{
	Solution s;
    vector<vector<int>> points1 = {{0, 2}, {2, 0}, {2, 2}, {0, 0}};
    cout << s.maxDistance(2, points1, 4) << endl;
    vector<vector<int>> points2 = {{0, 0}, {1, 2}, {2, 0}, {2, 2}, {2, 1}};
    cout << s.maxDistance(2, points2, 4) << endl;
    vector<vector<int>> points3 = {{0, 0}, {0, 1}, {0, 2}, {1, 2}, {2, 0}, {2, 2}, {2, 1}};
    cout << s.maxDistance(2, points3, 5) << endl;
	return 0;
}
