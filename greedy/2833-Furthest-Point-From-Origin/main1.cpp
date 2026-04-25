#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int lefts = 0, rights = 0, underscores = 0;
        for (const char move : moves) {
            if (move == 'L') ++lefts;
            else if (move == 'R') ++rights;
            else if (move == '_') ++underscores;
        }
        return abs(lefts - rights) + underscores;
    }
};

int main()
{
	Solution s;
    cout << s.furthestDistanceFromOrigin("L_RL__R") << endl;
    cout << s.furthestDistanceFromOrigin("_R__LL_") << endl;
    cout << s.furthestDistanceFromOrigin("_______") << endl;
	return 0;
}
