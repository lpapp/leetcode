#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
    int find(int x, vector<int>& parent) {
        if (parent[x] != x) parent[x] = find(parent[x], parent);
        return parent[x];
    };
public:
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        for (int i = 0; i < n; ++i) pipes.push_back({0, i + 1, wells[i]});
        sort(pipes.begin(), pipes.end(), [](const vector<int>& a, const vector<int>& b) { return a[2] < b[2]; });
        vector<int> parent(n + 1);
        iota(parent.begin(), parent.end(), 0);
        int result = 0;
        for (const vector<int>& edge : pipes) {
            int house1 = edge[0], house2 = edge[1], cost = edge[2];
            int root1 = find(house1, parent), root2 = find(house2, parent);
            if (root1 == root2) continue;
            parent[root1] = root2;
            result += cost;
            if (!--n) break;
        }
        return result;
    }
};

int main()
{
    Solution s;
	vector<vector<int>> isConnected1 = {
		{1, 1, 0},
		{1, 1, 0},
		{0, 0, 1}
	};
    vector<int> wells1 = {1, 2, 2};
    vector<vector<int>> pipes1 = {
        {1, 2, 1},
        {2, 3, 1}
    };
	cout << s.minCostToSupplyWater(3, wells1, pipes1) << endl;
    return 0;
}
