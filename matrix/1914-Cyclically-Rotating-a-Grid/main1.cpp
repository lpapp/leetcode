#include <algorithm>
#include <cassert>
#include <numeric>
#include <utility>
#include <vector>

using namespace std;

class Solution {
    static pair<int, int> coord(const int layer, int index, const int rows, const int columns) {
        const int width = columns - 2 * layer, height = rows - 2 * layer;
        if (index < width - 1) return {layer, layer + index};
        index -= width - 1;
        if (index < height - 1) return {layer + index, columns - layer - 1};
        index -= height - 1;
        if (index < width - 1) return {rows - layer - 1, columns - layer - 1 - index};
        index -= width - 1;
        return {rows - layer - 1 - index, layer};
    }
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        const int rows = grid.size(), columns = grid[0].size();
        for (int layer = 0; layer < min(rows, columns) / 2; ++layer) {
            const int perimeter = 2 * (rows - 2 * layer) + 2 * (columns - 2 * layer) - 4;
            const int rotation = k % perimeter;
            if (!rotation) continue;
            for (int start = 0; start < gcd(perimeter, rotation); ++start) {
                auto [row, column] = coord(layer, start, rows, columns);
                const int tmp = grid[row][column];
                int current = start;
                while (true) {
                    const int next = (current + rotation) % perimeter;
                    const auto [next_row, next_column] = coord(layer, next, rows, columns);
                    if (next == start) break;
                    grid[row][column] = grid[next_row][next_column];
                    row = next_row; column = next_column; current = next;
                }
                grid[row][column] = tmp;
            }
        }
        return grid;
    }
};

int main()
{
	Solution s;
    vector<vector<int>> grid1 = {{40, 10}, {30, 20}};
    vector<vector<int>> res1 = {{10, 20}, {40, 30}};
    assert(s.rotateGrid(grid1, 1) == res1);
    vector<vector<int>> grid2 = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    vector<vector<int>> res2 = {
        {3, 4, 8, 12},
        {2, 11, 10, 16},
        {1, 7, 6, 15},
        {5, 9, 13, 14}
    };
    assert(s.rotateGrid(grid2, 2) == res2);
	return 0;
}
