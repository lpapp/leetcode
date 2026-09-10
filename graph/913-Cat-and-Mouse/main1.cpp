#include <cassert>
#include <queue>
#include <vector>

using namespace std;

class Solution {
    static constexpr int HOLE = 0, MOUSE_START = 1, CAT_START = 2, MOUSE_TURN = 0, CAT_TURN = 1, TIE = 0, MOUSE_WIN = 1, CAT_WIN = 2;
public:
    int catMouseGame(vector<vector<int>>& graph) {
        const int n = graph.size();
        vector<vector<array<int, 2>>> dp(n, vector<array<int, 2>>(n, {0, 0}));
        vector<vector<array<int, 2>>> degree(n, vector<array<int, 2>>(n, {0, 0}));
        for (int mouse = 0; mouse < n; ++mouse) {
            for (int cat = 1; cat < n; ++cat) {
                degree[mouse][cat][MOUSE_TURN] = graph[mouse].size();
                degree[mouse][cat][CAT_TURN] = graph[cat].size();
            }
            for (const int neighbor : graph[HOLE]) --degree[mouse][neighbor][CAT_TURN];
        }
        queue<tuple<int, int, int>> q;
        for (int cat = 1; cat < n; ++cat) {
            dp[HOLE][cat][MOUSE_TURN] = MOUSE_WIN;
            dp[HOLE][cat][CAT_TURN] = MOUSE_WIN;
            q.emplace(HOLE, cat, MOUSE_TURN);
            q.emplace(HOLE, cat, CAT_TURN);
        }
        for (int pos = 1; pos < n; ++pos) {
            dp[pos][pos][MOUSE_TURN] = CAT_WIN;
            dp[pos][pos][CAT_TURN] = CAT_WIN;
            q.emplace(pos, pos, MOUSE_TURN);
            q.emplace(pos, pos, CAT_TURN);
        }
        auto prevStates = [&](int mouse, int cat, int turn) {
            const int prevTurn = turn ^ 1;
            vector<tuple<int, int, int>> res;
            if (prevTurn == CAT_TURN) for (const int prevCat : graph[cat]) { if (prevCat != HOLE) res.emplace_back(mouse, prevCat, prevTurn); }
            else for (const int prevMouse : graph[mouse]) res.emplace_back(prevMouse, cat, prevTurn);
            return res;
        };
        while (!q.empty()) {
            const auto [mouse, cat, turn] = q.front(); q.pop();
            const int result = dp[mouse][cat][turn];
            for (const auto& [prevMouse, prevCat, prevTurn] : prevStates(mouse, cat, turn)) {
                if (dp[prevMouse][prevCat][prevTurn] != TIE) continue;
                const bool canWin = (result == MOUSE_WIN && prevTurn == MOUSE_TURN) || (result == CAT_WIN && prevTurn == CAT_TURN);
                if (canWin) { dp[prevMouse][prevCat][prevTurn] = result; q.emplace(prevMouse, prevCat, prevTurn); }
                else if (--degree[prevMouse][prevCat][prevTurn] == 0) { dp[prevMouse][prevCat][prevTurn] = result; q.emplace(prevMouse, prevCat, prevTurn); }
            }
        }
        return dp[MOUSE_START][CAT_START][MOUSE_TURN];       
    }
};

int main()
{
    Solution s;
    vector<vector<int>> graph1 = {{2, 5}, {3}, {0, 4, 5}, {1, 4, 5}, {2, 3}, {0, 2, 3}};
    assert(s.catMouseGame(graph1) == 0);
    vector<vector<int>> graph2 = {{1, 3}, {0}, {3}, {0, 2}};
    assert(s.catMouseGame(graph2) == 1);
    return 0;
}
