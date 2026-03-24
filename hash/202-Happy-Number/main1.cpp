#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        for (unordered_set<int> hash; n != 1 && !hash.contains(n);) {
            hash.insert(n);
            int sum = 0;
            for (int last; n > 0; last = n % 10, sum += last * last, n /= 10);
            n = sum;
        }
        return n == 1;   
    }
};

int main()
{
	Solution s;
    cout << s.isHappy(19) << endl;
    cout << s.isHappy(2) << endl;
	return 0;
}
