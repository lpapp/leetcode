#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int currentStep = 1;
        for (int i = 0, previousStep = 0; i < n; ++i) {
            int nextStep = previousStep + currentStep;
            previousStep = currentStep;
            currentStep = nextStep;
        }
        return currentStep;
    }
};

int main()
{
	Solution solution;
	cout << solution.climbStairs(2) << endl;
	cout << solution.climbStairs(3) << endl;
	cout << solution.climbStairs(4) << endl;
	return 0;
}
