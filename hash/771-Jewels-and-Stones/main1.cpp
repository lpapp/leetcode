#include <array>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        array<int, 128> hash = {0};
        for (const char jewel : jewels) hash[jewel] = 1;
        int result = 0;
        for (char stone : stones) result += hash[stone];
        return result;
    }
};

int main()
{
	Solution s;
    cout << s.numJewelsInStones("aA", "aAAbbbb") << endl;
    cout << s.numJewelsInStones("z", "ZZ") << endl;
	return 0;
}
