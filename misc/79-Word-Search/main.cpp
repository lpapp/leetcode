#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Runtime Complexity: O(R*C*3^W) - go through each cell on the board and then
// branch out into three directions recursively after the first branching into
// four until the length of the word.
//
// Space complexity:   O(W)   - W recursion to find a matching word.
//
// R: the number of rows on the board.
// C: the number of columns on the board.
// W: the length of the word.

class Solution {
    bool dfs(std::vector<std::vector<char>>& board, const std::string& word, std::size_t row, std::size_t column, std::size_t wordIndex) {
        std::size_t sword = word.size();
        std::size_t rows = board.size();
        std::size_t columns = board.front().size();
      
        if (wordIndex == sword) return true;
    
        if (row < 0 || column < 0 || row >= rows || column >= columns) return false;
    
        if (char& cell = board[row][column]; cell == word[wordIndex]) {
            const char originalCell = cell;
    
            // Mark the cell as visited.
            cell = '-';
    
            // Check in each adjacent (horizonal and vertical) directions.
            const bool result = dfs(board, word, row - 1, column, wordIndex + 1)
                                || dfs(board, word, row + 1, column, wordIndex + 1)
                                || dfs(board, word, row, column - 1, wordIndex + 1)
                                || dfs(board, word, row, column + 1, wordIndex + 1);
    
            // Restore the original cell value after marking as visited.
            cell = originalCell;
            return result;
        }
          
        // Not matching then return false
        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        std::size_t sword = word.size();
        std::size_t rows = board.size();
        std::size_t columns = board.front().size();
        
        if (sword > rows * columns) return false;
        
        for (std::size_t row = 0; row < rows; ++row) {
            for (std::size_t column = 0; column < columns; ++column) {
                if (dfs(board, word, row, column, 0)) return true;
            }
        }
        return false;     
    }
};

int main()
{
    Solution solution;
    vector<vector<char>> i1{
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    
    cout << solution.exist(i1, "ABCCED") << endl;
    cout << solution.exist(i1, "SEE") << endl;
    cout << solution.exist(i1, "ABAB") << endl;
    
    return 0;
}
