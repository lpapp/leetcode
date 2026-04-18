#include <iostream>
#include <vector>

using namespace std;

class Solution {
	void dfs(int city, const vector<vector<int>>& isConnected, vector<bool>& visited, size_t numberOfCities) {
	    visited[city] = true;
	    for (size_t neighbor = 0; neighbor < numberOfCities; ++neighbor) if (!visited[neighbor] && isConnected[city][neighbor] == 1) dfs(neighbor, isConnected, visited, numberOfCities);
	};
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        const size_t numberOfCities = isConnected.size();
        int result = 0;
        vector<bool> visited(numberOfCities, false);
        for (size_t i = 0; i < numberOfCities; ++i) {
            if (!visited[i]) {
                dfs(i, isConnected, visited, numberOfCities);
                ++result;
            }
        }
        return result; 
    }
};

int main()
{
    Solution s;
	vector<vector<int>> isConnected1 = {
		{1, 1, 0},
		{1, 1, 0},
		{0, 0, 1}
	};
	cout << s.findCircleNum(isConnected1) << endl;
	vector<vector<int>> isConnected2 = {
		{1, 0, 0},
		{0, 1, 0},
		{0, 0, 1}
	};
	cout << s.findCircleNum(isConnected2) << endl;
    return 0;
}
