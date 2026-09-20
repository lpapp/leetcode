#include <array>
#include <cassert>
#include <vector>

using namespace std;

class SubrectangleQueries {
    vector<vector<int>> grid;
    vector<array<int, 5>> ops;
public:
    SubrectangleQueries(vector<vector<int>>& rectangle) : grid(rectangle) {}
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) { ops.push_back({row1, col1, row2, col2, newValue}); }
    int getValue(int row, int col) {
        for (int i = ops.size() - 1; i >= 0; --i) {
            const array<int, 5>& op = ops[i];
            if (row >= op[0] && row <= op[2] && col >= op[1] && col <= op[3]) return op[4];
        }
        return grid[row][col];
    }
};

int main()
{
    vector<vector<int>> rectangle1 = {{1, 2, 1}, {4, 3, 4}, {3, 2, 1}, {1, 1, 1}};
    SubrectangleQueries subrectangleQueries1(rectangle1);
    assert(subrectangleQueries1.getValue(0, 2) == 1);
    subrectangleQueries1.updateSubrectangle(0, 0, 3, 2, 5);
    assert(subrectangleQueries1.getValue(0, 2) == 5);
    assert(subrectangleQueries1.getValue(3, 1) == 5);
    subrectangleQueries1.updateSubrectangle(3, 0, 3, 2, 10);
    assert(subrectangleQueries1.getValue(3, 1) == 10);
    assert(subrectangleQueries1.getValue(0, 2) == 5);

    vector<vector<int>> rectangle2 = {{1, 1, 1}, {2, 2, 2}, {3, 3, 3}};
    SubrectangleQueries subrectangleQueries2(rectangle2);
    assert(subrectangleQueries2.getValue(0, 0) == 1);
    subrectangleQueries2.updateSubrectangle(0, 0, 2, 2, 100);
    assert(subrectangleQueries2.getValue(0, 0) == 100);
    assert(subrectangleQueries2.getValue(2, 2) == 100);
    subrectangleQueries2.updateSubrectangle(1, 1, 2, 2, 20);
    assert(subrectangleQueries2.getValue(2, 2) == 20);
    return 0;
}
