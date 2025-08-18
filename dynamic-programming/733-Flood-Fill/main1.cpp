#include <iostream>
#include <vector>

using namespace std;

class Solution {
	void PaintFill(vector<vector<int>>& screen, int row, int column, int rows, int columns, int oldColor, int newColor) {
		if (row < 0 || row >= rows || column < 0 || column >= columns) return;

		if (screen[row][column] == oldColor) {
			screen[row][column] = newColor;
			PaintFill(screen, row - 1, column, rows, columns, oldColor, newColor); // up
			PaintFill(screen, row + 1, column, rows, columns, oldColor, newColor); // down
			PaintFill(screen, row, column - 1, rows, columns, oldColor, newColor); // left
			PaintFill(screen, row, column + 1, rows, columns, oldColor, newColor); // right
		}
	}
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
		if (image[sr][sc] == color) return image;
        const int rows = image.size(), columns = image[0].size();
		PaintFill(image, sr, sc, rows, columns, image[sr][sc], color);
		return image;
    }
};

void printSolution(vector<vector<int>> input)
{
    cout << "[";
    for (const vector<int>& vectorItem : input) {
        cout << "[";
        for (const int item : vectorItem) cout << item << ", ";
        cout << "]";
    }
    cout << "]";
    cout << endl;
}

int main()
{
	Solution solution;

	vector<vector<int>> input1 = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
	printSolution(solution.floodFill(input1, 1, 1, 2));

    vector<vector<int>> input2 = {{0, 0, 0}, {0, 0, 0}};
	printSolution(solution.floodFill(input2, 0, 0, 0));
	return 0;
}
