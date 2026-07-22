#include <algorithm>
#include <bit>
#include <cassert>
#include <ranges>
#include <string>
#include <utility>
#include <vector>

using namespace std;

struct Group { int start; int length; };
class SparseTable {
    const int n;
    vector<vector<int>> st;
public:
    SparseTable(const vector<int>& nums) : n(nums.size()), st(bit_width(static_cast<unsigned
>(n)) + 1, vector<int>(n + 1)) {
        ranges::copy(nums, st[0].begin());
        for (int i = 1, logN = bit_width(static_cast<unsigned>(n)); i <= logN; ++i)
            for (int j = 0; j + (1 << i) <= n; ++j) st[i][j] = max(st[i - 1][j], st[i - 1][j
 + (1 << (i - 1))]);
    }
    int query(int l, int r) const {
        const int i = bit_width(static_cast<unsigned>(r - l + 1)) - 1;
        return max(st[i][l], st[i][r - (1 << i) + 1]);
    }
};

class Solution {
    pair<vector<Group>, vector<int>> getZeroGroups(const string& s) {
        vector<Group> zeroGroups;
        vector<int> zeroGroupIndex;
        for (int i = 0, n = s.length(); i < n; ++i) {
            if (s[i] == '0') {
                if (i > 0 && s[i - 1] == '0') ++zeroGroups.back().length;
                else zeroGroups.push_back({i, 1});
            }
            zeroGroupIndex.push_back(static_cast<int>(zeroGroups.size()) - 1);
        }
        return {zeroGroups, zeroGroupIndex};
    }
    vector<int> getZeroMergeLengths(const vector<Group>& zeroGroups) {
        vector<int> res;
        for (int i = 0, n = static_cast<int>(zeroGroups.size()) - 1; i < n; ++i) res.push_back(zeroGroups[i].length + zeroGroups[i + 1].length);
        return res;
    }
    pair<int, int> mapToAdjacentGroupIndices(int s, int e) { return {s, e - 1}; }
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        const int ones = ranges::count(s, '1');
        const auto [zeroGroups, zeroGroupIndex] = getZeroGroups(s);
        if (zeroGroups.empty()) return vector<int>(queries.size(), ones);
        const SparseTable st(getZeroMergeLengths(zeroGroups));
        vector<int> res;
        res.reserve(queries.size());
        for (const vector<int>& query : queries) {
            const int l = query[0];
            const int r = query[1];
            const int lLen = zeroGroupIndex[l] == -1 ? -1 : zeroGroups[zeroGroupIndex[l]].length - (l - zeroGroups[zeroGroupIndex[l]].start);
            const int rLen = zeroGroupIndex[r] == -1 ? -1 : r - zeroGroups[zeroGroupIndex[r]].start + 1;
            const auto [startAdj, endAdj] = mapToAdjacentGroupIndices(zeroGroupIndex[l] + 1, s[r] == '1' ? zeroGroupIndex[r] : zeroGroupIndex[r] - 1);
            int activeSections = ones;
            if (s[l] == '0' && s[r] == '0' && zeroGroupIndex[l] + 1 == zeroGroupIndex[r]) activeSections = max(activeSections, ones + lLen + rLen);
            else if (startAdj <= endAdj) activeSections = max(activeSections, ones + st.query(startAdj, endAdj));
            if (s[l] == '0' && zeroGroupIndex[l] + 1 <= (s[r] == '1' ? zeroGroupIndex[r] : zeroGroupIndex[r] - 1)) activeSections = max(activeSections, ones + lLen + zeroGroups[zeroGroupIndex[l] + 1].length);
            if (s[r] == '0' && zeroGroupIndex[l] < zeroGroupIndex[r] - 1) activeSections = max(activeSections, ones + rLen + zeroGroups[zeroGroupIndex[r] - 1].length);
            res.push_back(activeSections);
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> queries1 = {{0, 1}};
    vector<int> res1 = {1};
    assert(s.maxActiveSectionsAfterTrade("01", queries1) == res1);

    vector<vector<int>> queries2 = {{0, 3}, {0, 2}, {1, 3}, {2, 3}};
    vector<int> res2 = {4, 3, 1, 1};
    assert(s.maxActiveSectionsAfterTrade("0100", queries2) == res2);

    vector<vector<int>> queries3 = {{1, 5}, {0, 6}, {0, 4}};
    vector<int> res3 = {6, 7, 2};
    assert(s.maxActiveSectionsAfterTrade("1000100", queries3) == res3);

    vector<vector<int>> queries4 = {{0, 3}, {1, 4}, {1, 3}};
    vector<int> res4 = {4, 4, 2};
    assert(s.maxActiveSectionsAfterTrade("01010", queries4) == res4);
    return 0;
}
