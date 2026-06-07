#include <cassert>
#include <string>
#include <vector>

using namespace std;

class Solution {
    void dfs(int n, int k, string& current, int cost, vector<string>& res) {
        if (static_cast<int>(current.size()) == n) { if (cost <= k) res.push_back(current); return; }
        int index = current.size();
        current.push_back('0');
        dfs(n, k, current, cost, res);
        current.pop_back();
        if (current.empty() || current.back() != '1') {
            int newCost = cost + index;
            if (newCost <= k) { current.push_back('1'); dfs(n, k, current, newCost, res); current.pop_back(); }
        }
    }
public:
    vector<string> generateValidStrings(int n, int k) {
        vector<string> res;
        string current;
        dfs(n, k, current, 0, res);
        return res;
    }
};

int main()
{
	Solution s;
    vector<string> res1 = {"000", "010", "100"};
    assert(s.generateValidStrings(3, 1) == res1);
    vector<string> res2 = {"0", "1"};
    assert(s.generateValidStrings(1, 0) == res2);
	return 0;
}
