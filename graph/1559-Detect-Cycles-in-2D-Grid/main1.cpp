#include <array>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        const int rows = grid.size(), columns = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(columns, false));
        const array<int, 5> directions = {-1, 0, 1, 0, -1};
        for (int row = 0; row < rows; ++row) {
            for (int column = 0; column < columns; ++column) {
                if (visited[row][column]) continue;
                visited[row][column] = true;
                for (queue<array<int, 4>> q({{row, column, -1, -1}}); !q.empty();) {
                    auto current = q.front(); q.pop();
                    int currentRow = current[0], currentColumn = current[1], parentRow = current[2], parentColumn = current[3];
                    for (size_t dir = 0; dir < 4; ++dir) {
                        int nextRow = currentRow + directions[dir], nextColumn = currentColumn + directions[dir + 1];
                        if (nextRow < 0 || nextRow >= rows || nextColumn < 0 || nextColumn >= columns) continue;
                        if (grid[nextRow][nextColumn] != grid[currentRow][currentColumn] || (nextRow == parentRow && nextColumn == parentColumn)) continue;
                        if (visited[nextRow][nextColumn]) return true;
                        q.push({nextRow, nextColumn, currentRow, currentColumn});
                        visited[nextRow][nextColumn] = true;
                    }
                }
            }
        }
        return false;
    }
};

int main()
{
    Solution s;
	vector<vector<char>> grid1 = {
        {'a', 'a', 'a', 'a'},
        {'a', 'b', 'b', 'a'},
        {'a', 'b', 'b', 'a'},
        {'a', 'a', 'a', 'a'}
	};
	cout << s.containsCycle(grid1) << endl;
	vector<vector<char>> grid2 = {
        {'c', 'c', 'c', 'a'},
        {'c', 'd', 'c', 'c'},
        {'c', 'c', 'e', 'c'},
        {'f', 'c', 'c', 'c'}
	};
	cout << s.containsCycle(grid2) << endl;
	vector<vector<char>> grid3 = {
        {'a', 'b', 'b'},
        {'b', 'z', 'b'},
        {'b', 'b', 'a'}
	};
	cout << s.containsCycle(grid3) << endl;
    return 0;
}
