#include <cassert>
#include <vector>

using namespace std;

class Solution {
    static constexpr int MOD = 1'000'000'007;
    vector<vector<long long>> mul(const vector<vector<long long>>& A, const vector<vector<long long>>& B, int S) {
        vector<vector<long long>> C(S, vector<long long>(S, 0));
        for (int i = 0; i < S; ++i) {
            for (int k = 0; k < S; ++k) {
                if (A[i][k]) {
                    for (int j = 0; j < S; ++j) C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }
        return C;
    }
public:
    int zigZagArrays(int n, int l, int r) {
        const int m = r - l + 1;
        if (n == 1) return m;
        if (n == 2) return static_cast<long long>(m) * (m - 1) % MOD;
  
        const int S = 2 * m;
        vector<vector<long long>> T(S, vector<long long>(S, 0));
        for (int x = 0; x < m; ++x) {
            for (int y = 0; y < x; ++y) T[y + m][x] = 1;
            for (int y = x + 1; y < m; ++y) T[y][x + m] = 1;
        }
  
        vector<vector<long long>> result(S, vector<long long>(S, 0));
        for (int i = 0; i < S; ++i) result[i][i] = 1;
        for (int p = n - 2; p > 0; p >>= 1) {
            if (p & 1) result = mul(result, T, S);
            T = mul(T, T, S);
        }
  
        vector<long long> init(S, 0);
        for (int x = 0; x < m; ++x) { init[x] = x; init[x + m] = m - 1 - x; }
        long long res = 0;
        for (int i = 0; i < S; ++i) for (int j = 0; j < S; ++j) res = (res + result[i][j] * init[j]) % MOD;
        return res;
    }
};

int main()
{
    Solution s;
    assert(s.zigZagArrays(3, 4, 5) == 2);
    assert(s.zigZagArrays(3, 1, 3) == 10);
    return 0;
}
