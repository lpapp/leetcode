#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
    int twoEggDrop(int n) {
        // Solve x*(x+1)/2 = n for the smallest integer x where x*(x+1)/2 >= n
        double discriminant = 1.0 + 8.0 * n;
        double solution = (-1.0 + std::sqrt(discriminant)) / 2.0;
        return static_cast<int>(std::ceil(solution));
    }
};

int main()
{
	Solution solution;
	cout << solution.twoEggDrop(100) << endl;
	return 0;
}
