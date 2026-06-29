#include <bitset>
#include <cassert>
#include <string>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        static constexpr int A = 'z' - 'a' + 1;
        vector<array<int, A>> go(1, array<int, A>{});
        vector<bitset<100>> out(1);
        vector<int> fail(1, 0);
        for (int id = 0, n = patterns.size(); id < n; ++id) {
            int cur = 0;
            for (const char c : patterns[id]) {
                const int ch = c - 'a';
                if (!go[cur][ch]) {
                    go[cur][ch] = go.size();
                    go.push_back(array<int, A>{});
                    fail.push_back(0);
                    out.emplace_back();
                }
                cur = go[cur][ch];
            }
            out[cur].set(id);
        }
        queue<int> q;
        for (int c = 0; c < A; ++c) if (go[0][c]) q.push(go[0][c]);
        while (!q.empty()) {
            const int u = q.front(); q.pop();
            for (int c = 0; c < A; ++c) {
                const int v = go[u][c];
                if (v) { fail[v] = go[fail[u]][c]; out[v] |= out[fail[v]]; q.push(v); }
                else go[u][c] = go[fail[u]][c];
            }
        }
        int cur = 0;
        bitset<100> matched;
        for (const char c : word) { cur = go[cur][c - 'a']; matched |= out[cur]; }
        return matched.count();
    }
};

int main()
{
    Solution s;
    vector<string> patterns1 = {"a", "abc", "bc", "d"};
    assert(s.numOfStrings(patterns1, "abc") == 3);
    vector<string> patterns2 = {"a", "b", "c"};
    assert(s.numOfStrings(patterns2, "aaaaabbbbb") == 2);
    vector<string> patterns3 = {"a", "a", "a"};
    assert(s.numOfStrings(patterns3, "ab") == 3);
    vector<string> patterns4 = {"dojsf", "v", "hetnovaoigv", "ksvqfdojsf", "hetnovaoig", "yskjs", "sfr", "msurztkvppptsluk", "ndxffbkkvejuakduhdcfsdbgbt", "znhdgtwzbnh", "h", "ocaualfiscmbpnfalypmtdppymw", "w", "o", "sfjksvqfdo", "odqvzuc", "bozawheajcmlewptgssueylcxhx", "bno", "jhmarzsphxduvdktzqjiz", "j", "sfrjhetnov", "vxv", "ksvqfd", "ognwvqtadalmav", "yqbspvfwmvhycmghabigl", "qyfaiazgdqaw", "ojsfrj", "ojsfrjhetn", "fdojs", "do", "ovaoig", "k", "vrh", "jsfrjhetnovaoigvgk"};
    assert(s.numOfStrings(patterns4, "csfjksvqfdojsfrjhetnovaoigvgk") == 19);
    return 0;
}
