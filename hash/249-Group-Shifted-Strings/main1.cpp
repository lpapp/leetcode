#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> hash;
        for (const string& s : strings) {
            string normalized;
            int distance = s[0] - 'a';
            for (const char c : s) {
                char shifted = c - distance;
                if (shifted < 'a') shifted += 26;
                normalized.push_back(shifted);
            }
            hash[normalized].emplace_back(s);
        }
        vector<vector<string>> result;
        for (const auto& pair : hash) result.emplace_back(std::move(pair.second));
        return result;
    }
};

void printVectorVector(const vector<vector<string>>& input)
{
    cout << "[";
    for (const vector<string>& v: input) {
        cout << "[";
        for (const string& s: v) {
            cout << s << ",";
        }
        cout << "],";
    }
    cout << "]" << endl;
}

int main()
{
	Solution s;
    vector<string> strs1 = {"abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"};
    printVectorVector(s.groupStrings(strs1));
	return 0;
}
