#include <cassert>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        const int n = A.size();
        vector<int> res(n);
        unordered_set<int> hash;
        for (int i = 0, count = 0; i < n; ++i) { if (!hash.insert(A[i]).second) ++count; if (!hash.insert(B[i]).second) ++count; res[i] = count; }
        return res;
    }
};

int main()
{
	Solution s;
    vector<int> A1 = {1, 3, 2, 4};
    vector<int> B1 = {3, 1, 2, 4};
    vector<int> res1 = {0, 2, 3, 4};
    assert(s.findThePrefixCommonArray(A1, B1) == res1);
    vector<int> A2 = {2, 3, 1};
    vector<int> B2 = {3, 1, 2};
    vector<int> res2 = {0, 1, 3};
    assert(s.findThePrefixCommonArray(A2, B2) == res2);
	return 0;
}
