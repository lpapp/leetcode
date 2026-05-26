#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        
    }
};

int main()
{
	Solution s;
    vector<vector<int>> board1 = {
        {-1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1},
        {-1, 35, -1, -1, 13, -1},
        {-1, -1, -1, -1, -1, -1},
        {-1, 15, -1, -1, -1, -1}
    };
    assert(s.snakesAndLadders(board1) == 4);
    vector<vector<int>> board2 = {
        {-1, -1},
        {-1, 3}
    };
    assert(s.snakesAndLadders(board2) == 1);
	return 0;
}
