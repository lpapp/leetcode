#include <cassert>
#include <queue>
#include <vector>

using namespace std;

class Solution {

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjacencyList(numCourses);
        vector<int> inDegree(numCourses);
        for (const vector<int>& prerequisite : prerequisites) {
            int course = prerequisite[0], required = prerequisite[1];
            adjacencyList[required].push_back(course);
            ++inDegree[course];
        }
        queue<int> q;
        for (int course = 0; course < numCourses; ++course) if (!inDegree[course]) q.push(course);
        while (!q.empty()) {
            int current = q.front(); q.pop();
            --numCourses;
            for (int dependent : adjacencyList[current]) if (!--inDegree[dependent]) q.push(dependent);
        }
        return !numCourses;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> prerequisites1 = {{1, 0}};
    assert(s.canFinish(2, prerequisites1));
    vector<vector<int>> prerequisites2 = {{1, 0}, {0, 1}};
    assert(!s.canFinish(2, prerequisites2));
    return 0;
}
