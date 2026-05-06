#include <cassert>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int rows = boxGrid.size(), columns = boxGrid[0].size();
        vector<vector<char>> rotated(columns, vector<char>(rows));
        for (int row = 0; row < rows; ++row) for (int column = 0; column < columns; ++column) rotated[column][rows - row - 1] = boxGrid[row][column];
        for (int column = 0; column < rows; ++column) {
            queue<int> q;
            for (int row = columns - 1; row >= 0; --row) {
                if (rotated[row][column] == '*') { queue<int> emptyQueue; swap(q, emptyQueue); } 
                else if (rotated[row][column] == '.') q.push(row);
                else if (rotated[row][column] == '#' && !q.empty()) {
                    int emptyRow = q.front(); q.pop();
                    rotated[emptyRow][column] = '#';
                    rotated[row][column] = '.';
                    q.push(row);
                }
            }
        }
        return rotated;
    }
};

int main()
{
	Solution s;
    vector<vector<char>> boxGrid1 = {{'#', '.', '#'}};
    vector<vector<char>> res1 = {
        {'.'},
        {'#'},
        {'#'}
    };
    assert(s.rotateTheBox(boxGrid1) == res1);
    vector<vector<char>> boxGrid2 = {
        {'#', '.', '*', '.'},
        {'#', '#', '*', '.'}
    };
    vector<vector<char>> res2 = {
        {'#', '.'},
        {'#', '#'},
        {'*', '*'},
        {'.', '.'}
    };
    assert(s.rotateTheBox(boxGrid2) == res2);
    vector<vector<char>> boxGrid3 = {
        {'#', '#', '*', '.', '*', '.'},
        {'#', '#', '#', '*', '.', '.'},
        {'#', '#', '#', '.', '#', '.'}
    };
    vector<vector<char>> res3 = {
		{'.', '#', '#'},
        {'.', '#', '#'},
        {'#', '#', '*'},
        {'#', '*', '.'},
        {'#', '.', '*'},
        {'#', '.', '.'},
    };
    assert(s.rotateTheBox(boxGrid3) == res3);
	return 0;
}
