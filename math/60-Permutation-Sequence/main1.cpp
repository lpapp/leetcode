#include <cassert>
#include <string>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        constexpr int fact[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
        string candidates = "123456789"; candidates = candidates.substr(0, n);
        string res; res.reserve(n);
        for (int i = 0, rem = k - 1; i < n; ++i) {
            const int idx = rem / fact[n - 1 - i];
            rem %= fact[n - 1 - i];
            res += candidates[idx];
            candidates.erase(idx, 1);
        }
        return res;   
    }
};

int main()
{
	Solution s;
    assert(s.getPermutation(3, 3) == "213");
    assert(s.getPermutation(4, 9) == "2314");
    assert(s.getPermutation(3, 1) == "123");
	return 0;
}
