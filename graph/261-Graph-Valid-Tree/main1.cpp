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
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);
        for (const vector<int>& edge : edges) {
            const int rootA = find(edge[0], parent), rootB = find(edge[1], parent);
            if (rootA == rootB) return false;
            parent[rootA] = rootB;
            --n;
        }
        return n == 1;
    }
};

int main()
{
    Solution s;
	vector<vector<int>> edges1 = {
		{0, 1},
        {0, 2},
        {0, 3},
        {1, 4}
	};
	cout << s.validTree(5, edges1) << endl;
	vector<vector<int>> edges2 = {
        {0, 1},
        {1, 2},
        {2, 3},
        {1, 3},
        {1, 4}
	};
	cout << s.validTree(5, edges2) << endl;
    return 0;
}
