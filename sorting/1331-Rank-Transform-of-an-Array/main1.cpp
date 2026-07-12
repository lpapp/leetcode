#include <algorithm>
#include <cassert>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sorted = arr;
        ranges::sort(sorted);
        sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
        unordered_map<int, int> rank;
        rank.reserve(sorted.size());
        for (int i = 0, n = sorted.size(); i < n; ++i) rank[sorted[i]] = i + 1;
        vector<int> res;
        res.reserve(arr.size());
        for (const int x : arr) res.push_back(rank[x]);
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> arr1 = {40, 10, 20, 30};
    vector<int> res1 = {4, 1, 2, 3};
    assert(s.arrayRankTransform(arr1) == res1);

    vector<int> arr2 = {100, 100, 100};
    vector<int> res2 = {1, 1, 1};
    assert(s.arrayRankTransform(arr2) == res2);

    vector<int> arr3 = {37, 12, 28, 9, 100, 56, 80, 5, 12};
    vector<int> res3 = {5, 3, 4, 2, 8, 6, 7, 1, 3};
    assert(s.arrayRankTransform(arr3) == res3);
    return 0;
}
