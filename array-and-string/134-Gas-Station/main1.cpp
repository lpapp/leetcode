#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(), start = n - 1, balance = 0;
        for (int end = n - 1, visited = 0; visited < n; ) {
            balance += gas[end] - cost[end];
            ++visited;
            for (end = (end + 1) % n; balance < 0 && visited < n; ++visited) { --start; balance += gas[start] - cost[start]; }
        }
        return balance < 0 ? -1 : start;
    }
};

int main()
{
	Solution s;
    vector<int> gas1 = {1, 2, 3, 4, 5};
    vector<int> cost1 = {3, 4, 5, 1, 2};
    cout << s.canCompleteCircuit(gas1, cost1) << endl;
    vector<int> gas2 = {2, 3, 4};
    vector<int> cost2 = {3, 4, 3};
    cout << s.canCompleteCircuit(gas2, cost2) << endl;
	return 0;
}
