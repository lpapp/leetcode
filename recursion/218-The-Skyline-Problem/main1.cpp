#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        set<int> positions;
        for (const vector<int>& building : buildings) positions.insert({building[0], building[1]});
        map<int, int> positionToIndex;
        int index = 0;
        for (const int position : positions) positionToIndex[position] = index++;
        vector<int> maxHeights(positionToIndex.size(), 0);
        for (const auto& building : buildings) for (int i = positionToIndex[building[0]], rightIndex = positionToIndex[building[1]]; i < rightIndex; ++i) maxHeights[i] = max(maxHeights[i], building[2]);
        vector<int> sortedPositions(positions.cbegin(), positions.cend());
        vector<vector<int>> result;
        for (size_t i = 0; i < maxHeights.size(); ++i) {
            if (i + 1 >= maxHeights.size() || maxHeights[i] != maxHeights[i + 1]) result.push_back({sortedPositions[i], maxHeights[i]});
            else for (result.push_back({sortedPositions[i], maxHeights[i]}); i + 1 < maxHeights.size() && maxHeights[i] == maxHeights[i + 1]; ++i);
        }
        return result;
    }
};

void printVectorVector(const vector<vector<int>>& input)
{
    cout << "[";
    for (const vector<int>& v: input) {
        cout << "[";
        for (const int i: v) {
            cout << i << ",";
        }
        cout << "],";
    }
    cout << "]" << endl;
}

int main()
{
	Solution s;
    vector<vector<int>> buildings1 = {
        {2, 9, 10},
        {3, 7, 15},
        {5, 12, 12},
        {15, 20, 10},
        {19,24,8}
    };
    printVectorVector(s.getSkyline(buildings1));
    vector<vector<int>> buildings2 = { {0, 2, 3}, {2, 5, 3} };
    printVectorVector(s.getSkyline(buildings2));
	return 0;
}
