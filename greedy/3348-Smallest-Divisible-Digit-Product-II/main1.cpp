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
    static int minDigits(int n2, int n3, int n5, int n7) {
        int base = n7 + n5 + (n3 + 1) / 2 + (n2 + 2) / 3;
        if (n2 > 0 && n3 > 0) base = min(base, 1 + n7 + n5 + n3 / 2 + (n2 - 1 + 2) / 3);
        return base;
    }
    static string buildSuffix(int L, array<int, 4> need) {
        for (int k = 0; k < 4; ++k) need[k] = max(0, need[k]);
        string result(L, '1');
        for (int pos = 0; pos < L; ++pos) {
            for (int d = 1; d <= 9; ++d) {
                int r2 = max(0, need[0] - digitF[d][0]), r3 = max(0, need[1] - digitF[d][1]);
                int r5 = max(0, need[2] - digitF[d][2]), r7 = max(0, need[3] - digitF[d][3]);
                if (minDigits(r2, r3, r5, r7) <= L - pos - 1) {
                    result[pos] = '0' + d;
                    need = {r2, r3, r5, r7};
                    break;
                }
            }
        }
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
        int firstZero = n;
        array<int, 4> prefixF{};
        for (int i = 0; i < n; ++i) {
            int d = num[i] - '0';
            if (d == 0) { firstZero = i; break; }
            for (int k = 0; k < 4; ++k) prefixF[k] += digitF[d][k];
        }
        if (firstZero == n) {
            bool ok = true;
            for (int k = 0; k < 4; ++k) if (prefixF[k] < target[k]) { ok = false; break; }
            if (ok) return num;
        }
        for (int i = min(n - 1, firstZero); i >= 0; --i) {
            if (i < firstZero) for (int k = 0; k < 4; ++k) prefixF[k] -= digitF[num[i] - '0'][k];
            int startD = (num[i] - '0') + 1;
            for (int d = startD; d <= 9; ++d) {
                array<int, 4> need;
                for (int k = 0; k < 4; ++k) need[k] = max(0, target[k] - prefixF[k] - digitF[d][k]);
                int suffixLen = n - i - 1;
                if (minDigits(need[0], need[1], need[2], need[3]) <= suffixLen) {
                    string suffix = buildSuffix(suffixLen, need);
                    return num.substr(0, i) + char('0' + d) + suffix;
                }
            }
        }
        for (int len = n + 1; len <= n + 20; ++len) {
            if (minDigits(target[0], target[1], target[2], target[3]) <= len) return buildSuffix(len, target);
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
    assert(s.smallestNumber("12", 22020096000) == "2555678888888");
    return 0;
}
