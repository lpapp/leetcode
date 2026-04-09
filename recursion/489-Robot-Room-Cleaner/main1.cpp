#include <array>
#include <set>
#include <utility>

using namespace std;

 class Robot {
   public:
     bool move() { return true; }
     void turnLeft() {}
     void turnRight() {}
     void clean() {}
 };

class Solution {
    void dfs(int row, int column, size_t direction, const array<int, 5>& directions, Robot& robot, set<pair<int, int>>& visitedCells) {
        robot.clean();
        visitedCells.insert({row, column});
        for (size_t i = 0; i < 4; ++i) {
            int newDirection = (direction + i) % 4;
            int nextRow = row + directions[newDirection];
            int nextColumn = column + directions[newDirection + 1];
            if (!visitedCells.contains({nextRow, nextColumn}) && robot.move()) {
                dfs(nextRow, nextColumn, newDirection, directions, robot, visitedCells);
                robot.turnRight();
                robot.turnRight();
                robot.move();
                robot.turnRight();
                robot.turnRight();
            }
            robot.turnRight();
        }
    };
public:
    void cleanRoom(Robot& robot) {
        const array<int, 5> directions = {-1, 0, 1, 0, -1};
        set<pair<int, int>> visitedCells;
        dfs(0, 0, 0, directions, robot, visitedCells);
    }
};

int main()
{
	Solution s;
    Robot robot;
    s.cleanRoom(robot);
	return 0;
}
