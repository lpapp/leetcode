#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;
        for (const string& str : strs) {
            string sorted = str; sort(sorted.begin(), sorted.end());
            hash[sorted].emplace_back(str);
        }
        vector<vector<string>> result;
        for (auto& [key, value] : hash) result.emplace_back(value);
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
    vector<string> strs1 = {"eat", "tea", "tan", "ate", "nat", "bat"};
    printVectorVector(s.groupAnagrams(strs1));

    vector<string> strs2 = {""};
    printVectorVector(s.groupAnagrams(strs2));

    vector<string> strs3 = {"a"};
    printVectorVector(s.groupAnagrams(strs3));
	return 0;
}
