#include <algorithm>
#include <cassert>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        const int n = board.size(), totalCells = n * n;
        vector<bool> visited(totalCells + 1, false);
        visited[1] = true;
        int res = 0;
        for (queue<int> q({1}); !q.empty();) {
            for (int i = 0, size = q.size(); i < size; ++i) {
                int current = q.front(); q.pop();
                if (current == totalCells) return res;
                for (int next = current + 1; next <= min(current + 6, totalCells); ++next) {
                    int row = (next - 1) / n, column = (next - 1) % n;
                    if (row % 2 == 1) column = n - column - 1;
                    row = n - row - 1;
                    const int dest = (board[row][column] == -1) ? next : board[row][column];
                    if (!visited[dest]) {
                        visited[dest] = true;
                        q.push(dest);
                    }
                }
            }
            ++res;
        }
        return -1;
    }
};

int main()
{
	Solution s;
    vector<vector<int>> board1 = {
		{-1, -1, -1, -1, -1, -1},
		{-1, -1, -1, -1, -1, -1},
		{-1, -1, -1, -1, -1, -1},
		{-1, 35, -1, -1, 13, -1},
		{-1, -1, -1, -1, -1, -1},
		{-1, 15, -1, -1, -1, -1}
    };
    assert(s.snakesAndLadders(board1) == 4);
    vector<vector<int>> board2 = {
		{-1, -1},
		{-1, 3}
    };
    assert(s.snakesAndLadders(board2) == 1);
	return 0;
}
