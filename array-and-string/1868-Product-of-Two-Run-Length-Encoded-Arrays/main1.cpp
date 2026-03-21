#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> findRLEArray(vector<vector<int>>& encoded1, vector<vector<int>>& encoded2) {
        vector<vector<int>> result;
        size_t i2 = 0;
        for (const vector<int>& segment1 : encoded1) {
            int v1 = segment1[0], f1 = segment1[1];
            while (f1 > 0) {
                int minFrequency = min(f1, encoded2[i2][1]);
                int product = v1 * encoded2[i2][0];
                if (!result.empty() && result.back()[0] == product) result.back()[1] += minFrequency;
                else result.push_back({product, minFrequency});
                f1 -= minFrequency, encoded2[i2][1] -= minFrequency;
                if (!encoded2[i2][1]) ++i2;
            }
        }
        return result;
    }
};

void printVectorVector(const vector<vector<int>>& input)
{
    cout << "[";
    for (const vector<int>& v: input) {
        cout << "[";
        for (const int& i: v) {
            cout << i << ",";
        }
        cout << "],";
    }
    cout << "]" << endl;
}

int main()
{
	Solution s;
    vector<vector<int>> encoded11 = {
        {1, 3},
        {2, 5}
    };
    vector<vector<int>> encoded21 = {
        {3, 3},
        {4, 5}
    };
    printVectorVector(s.findRLEArray(encoded11, encoded21));

    vector<vector<int>> encoded12 = {
        {2, 6}
    };
    vector<vector<int>> encoded22 = {
        {3, 4},
        {4, 2}
    };
    printVectorVector(s.findRLEArray(encoded12, encoded22));

    vector<vector<int>> encoded13 = {
        {1, 3},
        {2, 2}
    };
    vector<vector<int>> encoded23 = {
        {3, 2},
        {4, 3}
    };
    printVectorVector(s.findRLEArray(encoded13, encoded23));

    vector<vector<int>> encoded14 = {
        {2, 3},
        {3, 2}
    };
    vector<vector<int>> encoded24 = {
        {5, 2},
        {1, 3}
    };
    printVectorVector(s.findRLEArray(encoded14, encoded24));
	return 0;
}
