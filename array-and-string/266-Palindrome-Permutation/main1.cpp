#include <array>
#include <iostream>
#include <string>

using namespace std;

class Solution {
	int toggle(int bitVector, int index) {
		if (index < 0) return bitVector;
		int mask = 1 << index;
		if (!(bitVector & mask)) bitVector |= mask;
		else bitVector &= ~mask;
		return bitVector;
	}

public:
    bool canPermutePalindrome(string s) {
		int bitVector = 0;
		for (const char c : s) bitVector = toggle(bitVector, c - 'a');
		return bitVector == 0 || !(bitVector & (bitVector - 1));
    }
};

int main()
{
	Solution s;
    cout << s.canPermutePalindrome("abcd") << endl;
    cout << s.canPermutePalindrome("racecar") << endl;
    cout << s.canPermutePalindrome("noon") << endl;
	return 0;
}
