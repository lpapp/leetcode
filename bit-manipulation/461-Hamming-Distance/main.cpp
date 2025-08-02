#include <iostream>

using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int count = 0;
        for (int c = x ^ y; c; c &= (c - 1)) ++count;
        return count;
    }
};

int main()
{
    Solution solution;
    cout << solution.hammingDistance(1, 4) << endl;
    cout << solution.hammingDistance(3, 1) << endl;
    return 0;
}
