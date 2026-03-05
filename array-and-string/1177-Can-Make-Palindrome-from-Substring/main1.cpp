#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        size_t sLength = s.size();
        int prefixSum[sLength + 1][26];
        memset(prefixSum, 0, sizeof(prefixSum));
        for (size_t i = 1; i <= sLength; ++prefixSum[i][s[i - 1] - 'a'], ++i) {
            for (size_t j = 0; j < 26; ++j) prefixSum[i][j] = prefixSum[i - 1][j];
        }
        vector<bool> result;
        for (const vector<int>& query : queries) {
            const size_t left = query[0], right = query[1], maxReplacements = query[2];
            size_t oddCount = 0;
            for (size_t j = 0; j < 26; ++j) {
                const size_t charCount = prefixSum[right + 1][j] - prefixSum[left][j];
                oddCount += charCount & 1;
            }
            result.emplace_back(oddCount / 2 <= maxReplacements);
        }
        return result;
    }
};

void printVector(const vector<bool>& result)
{
    cout << "[";
    for (const bool item : result) cout << item << ",";
    cout << "]" << endl;
}

int main()
{
	Solution s;
    vector<vector<int>> queries1 = {{3, 3, 0}, {1, 2, 0}, {0, 3, 1}, {0, 3, 2}, {0, 4, 1}};
    printVector(s.canMakePaliQueries("abcda", queries1));
    vector<vector<int>> queries2 = {{0, 1, 0}, {2, 2, 1}};
    printVector(s.canMakePaliQueries("lyn", queries2));
	return 0;
}
