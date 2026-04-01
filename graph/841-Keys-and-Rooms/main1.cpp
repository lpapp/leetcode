#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
    void dfs(int room, vector<vector<int>>& rooms, vector<bool>& visited, size_t& numberOfVisitedRooms) {
        if (visited[room]) return;
        visited[room] = true;
        ++numberOfVisitedRooms;
        for (int roomWithKey : rooms[room]) dfs(roomWithKey, rooms, visited, numberOfVisitedRooms);
    };
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        const size_t numberOfRooms = rooms.size();
        size_t numberOfVisitedRooms = 0;
        vector<bool> visited(numberOfRooms, false);
        dfs(0, rooms, visited, numberOfVisitedRooms);
        return numberOfVisitedRooms == numberOfRooms;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> rooms1 = {{1}, {2}, {3}, {}};
    cout << s.canVisitAllRooms(rooms1) << endl;
    vector<vector<int>> rooms2 = {{1, 3}, {3, 0, 1}, {2}, {0}};
    cout << s.canVisitAllRooms(rooms2) << endl;
    return 0;
}
