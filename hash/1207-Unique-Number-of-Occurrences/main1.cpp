#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> hash;
        for (const int i : arr) ++hash[i];
        unordered_set<int> seen;
        for (const auto& [_, count] : hash) if (!seen.insert(count).second) return false;
        return true;
    }
};

int main()
{
    Solution s;
    vector<int> arr1 = {1, 2, 2, 1, 1, 3};
    assert(s.uniqueOccurrences(arr1));
    vector<int> arr2 = {1, 2};
    assert(!s.uniqueOccurrences(arr2));
    vector<int> arr3 = {-3, 0, 1, -3, 1, 1, 1, -3, 10, 0};
    assert(s.uniqueOccurrences(arr3));
    return 0;
}
