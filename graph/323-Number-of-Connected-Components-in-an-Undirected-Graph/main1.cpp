#include <iostream>
#include <vector>

using namespace std;

class Solution {
    int dfs(int node, const vector<vector<int>>& adjacencyList, vector<bool>& visited) {
        if (visited[node]) return 0;
        visited[node] = true;
        for (int neighbor : adjacencyList[node]) dfs(neighbor, adjacencyList, visited);
        return 1;
    };
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjacencyList(n);
        for (const vector<int>& edge : edges) {
            const int nodeA = edge[0], nodeB = edge[1];
            // Add bidirectional edges (undirected graph)
            adjacencyList[nodeA].push_back(nodeB);
            adjacencyList[nodeB].push_back(nodeA);
        }
        vector<bool> visited(n, false);
        int result = 0;
        for (int i = 0; i < n; ++i) result += dfs(i, adjacencyList, visited);
        return result;
    }
};

int main()
{
    Solution s;
	vector<vector<int>> edges1 = {
        {0, 1},
        {0, 2},
        {3, 4}
	};
	cout << s.countComponents(6, edges1) << endl;
    return 0;
}
