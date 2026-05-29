#include <cassert>
#include <cstddef>
#include <vector>

using namespace std;

class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution {
    Node* dfs(int rowStart, int columnStart, int rowEnd, int columnEnd, vector<vector<int>>& grid) {
        bool zero = false, one = false;
        for (int row = rowStart; row <= rowEnd && !(zero && one); ++row) {
            for (int column = columnStart; column <= columnEnd && !(zero && one); ++column) {
                if (grid[row][column] == 1) one = true;
                else zero = true;
            }
        }
        bool leaf = !(zero && one), val = leaf && one;
        Node* node = new Node(val, leaf);
        if (leaf) return node;
        int midRow = (rowStart + rowEnd) / 2, midColumn = (columnStart + columnEnd) / 2;
        node->topLeft = dfs(rowStart, columnStart, midRow, midColumn, grid);
        node->topRight = dfs(rowStart, midColumn + 1, midRow, columnEnd, grid);
        node->bottomLeft = dfs(midRow + 1, columnStart, rowEnd, midColumn, grid);
        node->bottomRight = dfs(midRow + 1, midColumn + 1, rowEnd, columnEnd, grid);
        return node;
    }
public:
    Node* construct(vector<vector<int>>& grid) {
        const int n = grid.size();
        return dfs(0, 0, n - 1, n - 1, grid);
    }
};

int main()
{

	Solution s;
	vector<vector<int>> grid1 = {{0, 1}, {1, 0}};
	s.construct(grid1);
	vector<vector<int>> grid2 = {
		{1, 1, 1, 1, 0, 0, 0, 0},
		{1, 1, 1, 1, 0, 0, 0, 0},
		{1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 0, 0, 0, 0},
		{1, 1, 1, 1, 0, 0, 0, 0},
		{1, 1, 1, 1, 0, 0, 0, 0},
		{1, 1, 1, 1, 0, 0, 0, 0}
	};
	s.construct(grid2);
	return 0;
}
