#include <cassert>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
    int parent[1000];
    int find(int x) { while (parent[x] != x) { parent[x] = parent[parent[x]]; x = parent[x]; } return x; }
public:
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        iota(parent, parent + n, 0);
        vector<bool> res;
        for (vector<int>& req : requests) {
            int ru = find(req[0]), rv = find(req[1]);
            if (ru == rv) { res.push_back(true); continue; }
            bool ok = true;
            for (vector<int>& r : restrictions) {
                int rx = find(r[0]), ry = find(r[1]);
                if ((ru == rx && rv == ry) || (ru == ry && rv == rx)) { ok = false; break; }
            }
            res.push_back(ok);
            if (ok) parent[ru] = rv;
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> restrictions1 = {{0, 1}};
    vector<vector<int>> requests1 = {{0, 2}, {2, 1}};
    vector<bool> res1 = {true, false};
    assert(s.friendRequests(3, restrictions1, requests1) == res1);

    vector<vector<int>> restrictions2 = {{0, 1}};
    vector<vector<int>> requests2 = {{1, 2}, {0, 2}};
    vector<bool> res2 = {true, false};
    assert(s.friendRequests(3, restrictions2, requests2) == res2);

    vector<vector<int>> restrictions3 = {{0, 1}, {1, 2}, {2, 3}};
    vector<vector<int>> requests3 = {{0, 4}, {1, 2}, {3, 1}, {3, 4}};
    vector<bool> res3 = {true, false, true, false};
    assert(s.friendRequests(5, restrictions3, requests3) == res3);
    return 0;
}
