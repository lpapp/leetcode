#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> small;
        for (int i = 1; static_cast<long long>(i) * i <= n; ++i) if (n % i == 0) small.push_back(i);
        if (k <= static_cast<int>(small.size())) return small[k - 1];
        const int sq = small.back();
        const bool perfectSquare = sq * sq == n;
        const int largeCount = static_cast<int>(small.size()) - (perfectSquare ? 1 : 0);
        const int rankFromEnd = k - static_cast<int>(small.size());
        if (rankFromEnd > largeCount) return -1;
        const int idx = static_cast<int>(small.size()) - (perfectSquare ? 2 : 1) - (rankFromEnd - 1);
        return n / small[idx];
    }
};

int main()
{
    Solution s;
    assert(s.kthFactor(12, 3) == 3);
    assert(s.kthFactor(7, 2) == 7);
    assert(s.kthFactor(4, 4) == -1);
    return 0;
}
