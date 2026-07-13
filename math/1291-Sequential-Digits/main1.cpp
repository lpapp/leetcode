#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        for (int len = 2; len <= 9; ++len) {
            for (int start = 1; start + len - 1 <= 9; ++start) {
                int num = 0;
                for (int d = start, n = len; n--; ++d) num = num * 10 + d;
                if (num > high) return res;
                if (num >= low) res.push_back(num);
            }
        }
        return res;
    }
};


int main()
{
    Solution s;
    vector<int> res1 = {123, 234};
    assert(s.sequentialDigits(100, 300) == res1);
    vector<int> res2 = {1234, 2345, 3456, 4567, 5678, 6789, 12345};
    assert(s.sequentialDigits(1000, 13000) == res2);
    return 0;
}
