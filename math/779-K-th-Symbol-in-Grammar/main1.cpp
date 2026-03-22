#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
    int kthGrammar(int n, int k) {
        if (n == 1) return 0;
        const int middle = 1 << (n - 2);
        if (k <= middle) return kthGrammar(n - 1, k);
        return kthGrammar(n - 1, k - middle) ^ 1;
    }
};

int main()
{
	Solution solution;
	cout << solution.kthGrammar(1, 1) << endl;
	cout << solution.kthGrammar(2, 1) << endl;
	cout << solution.kthGrammar(2, 2) << endl;
	return 0;
}
