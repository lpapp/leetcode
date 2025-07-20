#include <iostream>
#include <vector>

using namespace std;

class Solution {
    // disjoint set (union-find) structure
    vector<int> parent;
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        parent.resize(n);
        for (int i = 0; i < n; ++i) parent[i] = i;

        // Perform the union operation
        for (const vector<int>& edge : edges) unionSet(find(edge[0]), find(edge[1]));

        // Check if the source and destination have the same root parent
        return find(source) == find(destination);
    }

    // Find the root parent of a node
    int find(int node) {
        // Path Compression: Recursively makes the parents of the node
	// along the path from node to its root parent point directly to the
        // root parent.
        if (parent[node] != node) parent[node] = find(parent[node]);
        return parent[node];
    }

    // Perform the union operation on two subsets
    void unionSet(int source, int destination) {
        // Find the root parents of the nodes
        int rootSource = find(source), rootDestination = find(destination);

        // Union by setting the parent of rootSource to rootDestination
        if (rootSource != rootDestination)
            parent[rootSource] = rootDestination;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> edges{{0,1}, {1,2}, {2,0}, {5,4}};
    cout << s.validPath(3, edges, 0, 2) << true << endl;

    vector<vector<int>> edges2{{0,1}, {0,2}, {3,5}, {5,4}, {4,3}};
    cout << s.validPath(6, edges2, 0, 5) << false << endl;
    return 0;
}
