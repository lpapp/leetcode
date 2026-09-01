#include <cassert>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size(), n = classroom[0].size(), sr = 0, sc = 0, k = 0;
        vector<vector<int>> id(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) {
            if (classroom[i][j] == 'S') { sr = i; sc = j; }
            else if (classroom[i][j] == 'L') id[i][j] = k++;
        }
        if (!k) return 0;
        const int full = (1 << k) - 1;
        vector<int> best(m * n * (full + 1), -1);
        best[(sr * n + sc) * (full + 1) + full] = energy;
        constexpr int dirs[5] = {-1, 0, 1, 0, -1};
        queue<tuple<int, int, int, int>> q({{sr, sc, energy, full}});
        for (int moves = 0; !q.empty(); ++moves) {
            for (int sz = q.size(); sz--; ) {
                const auto [r, c, e, mask] = q.front(); q.pop();
                if (!mask) return moves;
                if (e <= 0) continue;
                for (int d = 0; d < 4; ++d) {
                    const int nr = r + dirs[d], nc = c + dirs[d + 1];
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n || classroom[nr][nc] == 'X') continue;
                    const char cell = classroom[nr][nc];
                    const int ne = cell == 'R' ? energy : e - 1;
                    const int nmask = cell == 'L' ? (mask & ~(1 << id[nr][nc])) : mask;
                    const int idx = (nr * n + nc) * (full + 1) + nmask;
                    if (best[idx] >= ne) continue;
                    best[idx] = ne;
                    q.emplace(nr, nc, ne, nmask);
                }
            }
        }
        return -1;       
    }
};

int main()
{
    Solution s;
    vector<string> classroom1 = {"S.", "XL"};
    assert(s.minMoves(classroom1, 2) == 2);
    vector<string> classroom2 = {"LS", "RL"};
    assert(s.minMoves(classroom2, 4) == 3);
    vector<string> classroom3 = {"L.S", "RXL"};
    assert(s.minMoves(classroom3, 3) == -1);
    return 0;
}
