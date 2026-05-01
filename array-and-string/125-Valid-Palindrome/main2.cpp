#include <array>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {	
        const int bitVector = createBitVector(s);
        return bitVector == 0 || checkExactlyOneBitSet(bitVector);       
    }

    /* Create a bit vector for the string. For each letter with i, toggle the ith
     * bit.
     */
    int createBitVector(string phrase) {
        int bitVector = 0;
        for (const char c : phrase) {
            const int x = static_cast<int>(c);
            bitVector = toggle(bitVector, x);
        }
        return bitVector;
    }

    /* Toggle the ith bit in the integer. */
    int toggle(int bitVector, int index)
    {
        if (index < 0) return bitVector;
        const int mask = 1 << index;
        if ((bitVector & mask) == 0) {
            bitVector |= mask;
        } else {
            bitVector &= ~mask;
        }
    
        return bitVector;
    }
 
    /* Check that exactly one bit is set by subtracting one from the integer
     * and ANDing it with the original integer.
     */
    bool checkExactlyOneBitSet(int bitVector) {
        return !(bitVector & (bitVector - 1));
    }
};

int main()
{
    Solution solution;
    cout << solution.isPalindrome("A man, a plan, a canal: Panama") << endl;
    cout << solution.isPalindrome("race a car") << endl;
    cout << solution.isPalindrome(" ") << endl;
    return 0;
}
