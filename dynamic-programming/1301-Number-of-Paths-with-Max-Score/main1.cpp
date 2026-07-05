#include <cassert>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        const int MOD = 1'000'000'007, n = board.size();
        vector<vector<int>> f(n, vector<int>(n, -1)); f[n - 1][n - 1] = 0;
        vector<vector<int>> g(n, vector<int>(n, 0)); g[n - 1][n - 1] = 1;
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (board[i][j] == 'X' || board[i][j] == 'S') continue;
                for (const int di : {0, 1}) {
                    for (const int dj : {0, 1}) {
                        if (!di && !dj) continue;
                        int ni = i + di, nj = j + dj;
                        if (ni >= n || nj >= n || f[ni][nj] < 0) continue;
                        if (f[ni][nj] > f[i][j]) { f[i][j] = f[ni][nj]; g[i][j] = g[ni][nj]; } 
                        else if (f[ni][nj] == f[i][j]) g[i][j] = (g[i][j] + g[ni][nj]) % MOD;
                    }
                }
                if (f[i][j] >= 0 && board[i][j] >= '1' && board[i][j] <= '9') f[i][j] += board[i][j] - '0';
            }
        }
        if (f[0][0] < 0) return {0, 0};
        return {f[0][0], g[0][0]};
    }
};

int main()
{
    Solution s;
    vector<string> board1 = {"E23", "2X2", "12S"};
    vector<int> res1 = {7, 1};
    assert(s.pathsWithMaxScore(board1) == res1);
    vector<string> board2 = {"E12", "1X1", "21S"};
    vector<int> res2 = {4, 2};
    assert(s.pathsWithMaxScore(board2) == res2);
    vector<string> board3 = {"E11", "XXX", "11S"};
    vector<int> res3 = {0, 0};
    assert(s.pathsWithMaxScore(board3) == res3);
    return 0;
}
