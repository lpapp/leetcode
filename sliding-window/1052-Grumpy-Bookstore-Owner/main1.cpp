#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int base = 0, rescued = 0;
        for (int i = 0; i < minutes; ++i) { base += customers[i] * (grumpy[i] ^ 1); rescued += customers[i] * grumpy[i]; }
        int maxRescued = rescued;
        for (int i = minutes, n = customers.size(); i < n; ++i) {
            base += customers[i] * (grumpy[i] ^ 1);
            rescued += customers[i] * grumpy[i] - customers[i - minutes] * grumpy[i - minutes];
            maxRescued = max(maxRescued, rescued);
        }
        return base + maxRescued;
    }
};

int main()
{
    Solution s;
    vector<int> customers1 = {1, 0, 1, 2, 1, 1, 7, 5};
    vector<int> grumpy1 = {0, 1, 0, 1, 0, 1, 0, 1};
    assert(s.maxSatisfied(customers1, grumpy1, 3) == 16);
    vector<int> customers2 = {1};
    vector<int> grumpy2 = {0};
    assert(s.maxSatisfied(customers2, grumpy2, 1) == 1);
    return 0;
}
