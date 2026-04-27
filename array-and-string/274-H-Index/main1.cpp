#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.rbegin(), citations.rend());
        for (int h = citations.size(); h > 0; --h) if (citations[h - 1] >= h) return h;
        return 0;   
    }
};

int main()
{
	Solution s;
    vector<int> citations1 = {3, 0, 6, 1, 5};
    cout << s.hIndex(citations1) << endl;
    vector<int> citations2 = {1, 3, 1};
    cout << s.hIndex(citations2) << endl;
	return 0;
}
