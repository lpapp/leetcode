#include <array>
#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        set<int> positions;
        for (const vector<int>& building : buildings) positions.insert({building[0], building[1]});
        std::priority_queue<array<int, 3>> pq;
        size_t index = 0;
        const size_t numberOfBuildings = buildings.size();
        vector<vector<int>> result;
        for (const int position : positions) {
            for (; index < numberOfBuildings && buildings[index][0] <= position; ++index) {
                const vector<int> building = buildings[index];
                pq.push({building[2], building[0], building[1]});
            }
            while (!pq.empty() && pq.top()[2] <= position) pq.pop();
            int height = 0;
            if (!pq.empty()) height = pq.top()[0];
            if (!result.empty() && result.back()[1] == height) continue;
            result.push_back({position, height});
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
