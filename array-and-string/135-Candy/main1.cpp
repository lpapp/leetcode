#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int ratingsLength = ratings.size();
        int result = ratingsLength;
        for (int i = 1; i < ratingsLength;) {
            if (ratings[i] == ratings[i - 1]) { ++i; continue; }
            int increaseLength = 0;
            for (; i < ratingsLength && ratings[i] > ratings[i - 1]; ++increaseLength, result += increaseLength, ++i);
            int decreaseLength = 0;
            for (; i < ratingsLength && ratings[i] < ratings[i - 1]; ++decreaseLength, result += decreaseLength, ++i);
            result -= min(increaseLength, decreaseLength);
        }
        return result;
    }
};

int main()
{
	Solution s;
    vector<int> ratings1 = {1, 0, 2};
    cout << s.candy(ratings1) << endl;
    vector<int> ratings2 = {1, 2, 2};
    cout << s.candy(ratings2) << endl;
	return 0;
}
