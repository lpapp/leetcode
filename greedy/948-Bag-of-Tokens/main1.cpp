#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        ranges::sort(tokens);
        int res = 0;
        for (int left = 0, right = static_cast<int>(tokens.size()) - 1, score = 0; left <= right; ) {
            if (power >= tokens[left]) { power -= tokens[left++]; res = max(res, ++score); }
            else if (score > 0) { power += tokens[right--]; --score; }
            else break;
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> tokens1 = {100};
    assert(s.bagOfTokensScore(tokens1, 50) == 0);
    vector<int> tokens2 = {200, 100};
    assert(s.bagOfTokensScore(tokens2, 150) == 1);
    vector<int> tokens3 = {100, 200, 300, 400};
    assert(s.bagOfTokensScore(tokens3, 200) == 2);
    return 0;
}
