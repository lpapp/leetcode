#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

// Runtime Complexity: O(n)
//
// Space complexity:   O(1)
//
// n: length of the string

class Solution {
  vector<int> parent;
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
      parent.resize(n);
      // Initialise the root parent to itself.
      for (int i = 0; i < n; ++i)
        parent[i] = i;

      for (const vector<int>& edge : edges)
        unionSet(find(edge[0]), find(edge[1]));

      // If the root parents are the same, there is a valid path between them.
      return find(source) == find(destination);
    }

    int find(int x) {
        if (parent[x] != x)
          parent[x] = find(parent[x]);

        return parent[x];
    }

    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY)
          parent[rootX] = rootY;       
    }
};

int main()
{
  Solution solution;
  std::vector<std::vector<int>> i1{
    {0, 1},
    {1, 2},
    {2, 0},
  };
  std::cout << solution.validPath(3, i1, 0, 2) << std::endl;

  std::vector<std::vector<int>> i2{
    {0, 1},
    {0, 2},
    {3, 5},
    {5, 4},
    {4, 3},
  };
  std::cout << solution.validPath(6, i2, 0, 5) << std::endl;

  return 0;
}
