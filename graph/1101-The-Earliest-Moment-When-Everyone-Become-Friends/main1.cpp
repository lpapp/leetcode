#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
    int find(int person, vector<int>& parent) {
        if (parent[person] == person) return person;
        return parent[person] = find(parent[person], parent);
    };
public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        sort(logs.begin(), logs.end());
        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);
        for (const vector<int>& log : logs) {
            int timestamp = log[0], person1 = log[1], person2 = log[2];
            int root1 = find(person1, parent), root2 = find(person2, parent);
            if (root1 != root2) {
                parent[root1] = root2;
                --n;
            }
            if (n == 1) return timestamp;
        }
        return -1;
    }
};

int main()
{
    Solution s;
	vector<vector<int>> logs1 = {
        {3, 0, 1},
        {7, 0, 2},
        {4, 3, 4},
        {6, 3, 5},
        {9, 2, 5}
	};
	cout << s.earliestAcq(logs1, 6) << endl;
    return 0;
}
