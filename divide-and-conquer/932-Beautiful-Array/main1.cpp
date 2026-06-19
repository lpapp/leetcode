#include <algorithm>
#include <cassert>
#include <numeric>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> beautifulArray(int n) {
          vector<int> res = {1}, tmp; res.reserve(n); tmp.reserve(n);
          for (; static_cast<int>(res.size()) < n; swap(res, tmp)) {
              tmp.clear();
              for (int x : res) if (x * 2 - 1 <= n) tmp.push_back(x * 2 - 1);
              for (int x : res) if (x * 2 <= n) tmp.push_back(x * 2);
          }
          return res;
    }
};

bool isBeautiful(const vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n; ++i)
        for (int j = i + 2; j < n; ++j)
            for (int k = i + 1; k < j; ++k)
                if (2 * a[k] == a[i] + a[j]) return false;
    return true;
}

int main()
{
    Solution s;
    vector<int> expected1(4);
    iota(expected1.begin(), expected1.end(), 1);
    vector<int> res1 = s.beautifulArray(4);
    assert(static_cast<int>(res1.size()) == 4);
    vector<int> sorted1 = res1;
    ranges::sort(sorted1);
    assert(sorted1 == expected1);
    assert(isBeautiful(res1));

    vector<int> expected2(5);
    iota(expected2.begin(), expected2.end(), 1);
    vector<int> res2 = s.beautifulArray(5);
    assert(static_cast<int>(res2.size()) == 5);
    vector<int> sorted2 = res2;
    ranges::sort(sorted2);
    assert(sorted2 == expected2);
    assert(isBeautiful(res2));
    return 0;
}
