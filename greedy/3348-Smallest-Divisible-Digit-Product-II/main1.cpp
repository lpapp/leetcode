#include <algorithm>
#include <array>
#include <cassert>
#include <string>
#include <vector>

using namespace std;

class Solution {
    static constexpr array<int, 4> digitF[10] = {
        {0,0,0,0}, {0,0,0,0}, {1,0,0,0}, {0,1,0,0}, {2,0,0,0},
        {0,0,1,0}, {1,1,0,0}, {0,0,0,1}, {3,0,0,0}, {0,2,0,0},
    };
    static string buildSuffix(int L, array<int, 4> need) {
        for (int k = 0; k < 4; ++k) need[k] = max(0, need[k]);
        vector<int> digits;
        for (int i = 0; i < need[3]; ++i) digits.push_back(7);
        for (int i = 0; i < need[2]; ++i) digits.push_back(5);
        int n2 = need[0], n3 = need[1];
        if (n2 % 3 == 1 && n3 % 2 == 1) { digits.push_back(6); --n2; --n3; }
        for (int i = 0; i < n3 / 2; ++i) digits.push_back(9);
        if (n3 & 1) digits.push_back(3);
        for (int i = 0; i < n2 / 3; ++i) digits.push_back(8);
        if (n2 % 3 == 2) digits.push_back(4);
        else if (n2 % 3 == 1) digits.push_back(2);
        if ((int)digits.size() > L) return "";
        ranges::sort(digits, greater<int>());
        string result(L, '1');
        int pos = L - 1;
        for (int d : digits) result[pos--] = '0' + d;
        return result;
    }
public:
    string smallestNumber(string num, long long t) {
        array<int, 4> target{};
        long long tmp = t;
        constexpr int primes[4] = {2, 3, 5, 7};
        for (int k = 0; k < 4; ++k) while (tmp % primes[k] == 0) { ++target[k]; tmp /= primes[k]; }
        if (tmp != 1) return "-1";
        const int n = num.size();
        vector<array<int, 4>> prefixF(n + 1, {0, 0, 0, 0});
        int firstZero = n;
        for (int i = 0; i < n; ++i) {
            int d = num[i] - '0';
            if (d == 0) { firstZero = i; break; }
            for (int k = 0; k < 4; ++k) prefixF[i + 1][k] = prefixF[i][k] + digitF[d][k];
        }
        if (firstZero == n) {
            bool ok = true;
            for (int k = 0; k < 4; ++k) if (prefixF[n][k] < target[k]) { ok = false; break; }
            if (ok) return num;
        }
        for (int i = n - 1; i >= 0; --i) {
            if (i > firstZero) continue;
            int startD = (num[i] - '0') + 1;
            for (int d = startD; d <= 9; ++d) {
                array<int, 4> need;
                for (int k = 0; k < 4; ++k) need[k] = target[k] - prefixF[i][k] - digitF[d][k];
                int suffixLen = n - i - 1;
                if (suffixLen == 0) {
                    bool ok = true;
                    for (int k = 0; k < 4; ++k) if (need[k] > 0) { ok = false; break; }
                    if (ok) return num.substr(0, i) + char('0' + d);
                } else {
                    string suffix = buildSuffix(suffixLen, need);
                    if (!suffix.empty()) return num.substr(0, i) + char('0' + d) + suffix;
                }
            }
        }
        for (int len = n + 1; len <= n + 20; ++len) {
            string suffix = buildSuffix(len, target);
            if (!suffix.empty()) return suffix;
        }
        return "-1";  
    }
};

int main()
{
    Solution s;
    assert(s.smallestNumber("1234", 256) == "1488");
    assert(s.smallestNumber("12355", 50) == "12355");
    assert(s.smallestNumber("11111", 26) == "-1");
    return 0;
}
