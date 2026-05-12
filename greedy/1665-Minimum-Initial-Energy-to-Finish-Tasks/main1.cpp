#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
         sort(tasks.begin(), tasks.end(), [](const auto& taskA, const auto& taskB) { return taskA[0] - taskA[1] < taskB[0] - taskB[1]; });
        int res = 0, energy = 0;
        for (const vector<int>& task : tasks) {
            const int actual = task[0], minimum = task[1];
            if (energy < minimum) { res += minimum - energy; energy = minimum; }
            energy -= actual;
        }
        return res;
    }
};

int main()
{
	Solution s;
    vector<vector<int>> tasks1 = {{1, 2}, {2, 4}, {4, 8}};
    assert(s.minimumEffort(tasks1) == 8);
    vector<vector<int>> tasks2 = {{1, 3}, {2, 4}, {10, 11}, {10, 12}, {8, 9}};
    assert(s.minimumEffort(tasks2) == 32);
    vector<vector<int>> tasks3 = {{1, 7}, {2, 8}, {3, 9}, {4, 10}, {5, 11}, {6, 12}};
    assert(s.minimumEffort(tasks3) == 27);
	return 0;
}
