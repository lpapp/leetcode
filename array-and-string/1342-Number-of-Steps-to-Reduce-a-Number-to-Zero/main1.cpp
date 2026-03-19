#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int numberOfSteps(int num) {
        int result;
        for (result = 0; num; ++result) num = (num & 1) ? (num - 1) : (num >> 1);
        return result;
    }
};

int main()
{
	Solution s;
    cout << s.numberOfSteps(14) << endl;
    cout << s.numberOfSteps(8) << endl;
    cout << s.numberOfSteps(123) << endl;
	return 0;
}
