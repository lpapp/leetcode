#include <cassert>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> res(seq.size());
        for (int i = 0, n = seq.size(), depth = 0; i < n; ++i) res[i] = (seq[i] == '(' ? depth++ : --depth) & 1;
        return res;
    }
};

int validatedDepth(const string& seq, const vector<int>& lab, int group) {
    int bal = 0, mx = 0;
    for (int i = 0, n = seq.size(); i < n; ++i) {
        if (lab[i] != group) continue;
        bal += seq[i] == '(' ? 1 : -1;
        mx = max(mx, bal);
        if (bal < 0) return -1;
    }
    return bal == 0 ? mx : -1;
}

int optimalDepth(const string& seq) {
    int bal = 0, mx = 0;
    for (char c : seq) { bal += c == '(' ? 1 : -1; mx = max(mx, bal); }
    return (mx + 1) / 2;
}

void check(Solution& s, const string& seq) {
    const vector<int> lab = s.maxDepthAfterSplit(seq);
    const int da = validatedDepth(seq, lab, 0);
    const int db = validatedDepth(seq, lab, 1);
    assert(da != -1 && db != -1);
    assert(max(da, db) == optimalDepth(seq));
}

int main() {
    Solution s;
    check(s, "(()())");
    check(s, "()(())()");
    return 0;
}
