#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        for (int i = pref.size() - 1; i > 0; --i) pref[i] ^= pref[i - 1];
        return pref;
    }
};

int main()
{
    Solution s;
    vector<int> pref1 = {5, 2, 0, 3, 1};
    vector<int> res1 = {5, 7, 2, 3, 2};
    assert(s.findArray(pref1) == res1);
    vector<int> pref2 = {13};
    vector<int> res2 = {13};
    assert(s.findArray(pref2) == res2);
    return 0;
}
