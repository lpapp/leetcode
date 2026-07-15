#include <cassert>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;
        const int n = routes.size();
        unordered_map<int, vector<int>> stopToBuses;
        for (int i = 0; i < n; ++i) for (const int stop : routes[i]) stopToBuses[stop].push_back(i);
        if (!stopToBuses.contains(source) || !stopToBuses.contains(target)) return -1;
        vector<bool> visitedBus(n, false);
        unordered_set<int> visitedStop;
        queue<int> q;
        for (const int bus : stopToBuses[source]) { visitedBus[bus] = true; q.push(bus); }
        visitedStop.insert(source);
        for (int buses = 1; !q.empty(); ++buses) {
            for (int sz = q.size(); sz > 0; --sz) {
                const int bus = q.front(); q.pop();
                for (const int stop : routes[bus]) {
                    if (stop == target) return buses;
                    if (!visitedStop.insert(stop).second) continue;
                    for (const int nextBus : stopToBuses[stop]) if (!visitedBus[nextBus]) { visitedBus[nextBus] = true; q.push(nextBus); }
                }
            }
        }
        return -1;   
    }
};

int main()
{
    Solution s;
    vector<vector<int>> routes1 = {{1, 2, 7}, {3, 6, 7}};
    assert(s.numBusesToDestination(routes1, 1, 6) == 2);
    vector<vector<int>> routes2 = {{7, 12}, {4, 5, 15}, {6}, {15, 19}, {9, 12, 13}};
    assert(s.numBusesToDestination(routes2, 15, 12) == -1);
    return 0;
}
