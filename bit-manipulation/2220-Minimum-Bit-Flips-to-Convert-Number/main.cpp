#include <iostream>

using namespace std;

class Solution {
public:
    int minBitFlips(int start, int goal) {
		int count = 0;
		for (int c = start ^ goal; c; c &= (c - 1)) ++count;
		return count;
    }
};

int main()
{
	Solution solution;
	cout << solution.minBitFlips(10, 7) << endl;
	cout << solution.minBitFlips(3, 4) << endl;
	return 0;
}
