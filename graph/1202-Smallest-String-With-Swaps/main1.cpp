#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
    int find(int x, vector<int>& parent) {
        if (parent[x] != x) parent[x] = find(parent[x], parent);
        return parent[x];
    };
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        const size_t sLength = s.size();
        vector<int> parent(sLength);
        iota(parent.begin(), parent.end(), 0);
        vector<vector<char>> componentsChars(sLength);
        for (const auto& pair : pairs) {
            int indexA = pair[0], indexB = pair[1];
            parent[find(indexA, parent)] = find(indexB, parent);
        }
        for (size_t i = 0; i < sLength; ++i) {
            const int root = find(i, parent);
            componentsChars[root].push_back(s[i]);
        }
        for (vector<char>& componentChars : componentsChars) sort(componentChars.rbegin(), componentChars.rend());
        for (size_t i = 0; i < sLength; ++i) {
            const size_t root = find(i, parent);
            vector<char>& componentChars = componentsChars[root];
            s[i] = componentChars.back();
            componentChars.pop_back();
        }
        return s;
    }
};

int main()
{
    Solution s;
	vector<vector<int>> pairs1 = {
        {0, 3},
        {1, 2}
	};
	cout << s.smallestStringWithSwaps("dcab", pairs1) << endl;
	vector<vector<int>> pairs2 = {
        {0, 3},
        {1, 2},
        {0, 2}
	};
	cout << s.smallestStringWithSwaps("dcab", pairs2) << endl;
	vector<vector<int>> pairs3 = {
        {0, 1},
        {1, 2}
	};
	cout << s.smallestStringWithSwaps("cab", pairs3) << endl;
    return 0;
}
