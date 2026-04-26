#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> s;
        for (int i = prices.size() - 1; i >= 0; --i) {
            const int price = prices[i];
            while (!s.empty() && s.top() > price) s.pop();
            if (!s.empty()) prices[i] -= s.top();
            s.push(price);
        }
        return prices;       
    }
};

void printVector(vector<int> input)
{
    for (const int item : input) cout << item << ", ";
    cout << endl;
}

int main()
{
	Solution s;
    vector<int> prices1 = {8, 4, 6, 2, 3};
    printVector(s.finalPrices(prices1));
    vector<int> prices2 = {1, 2, 3, 4, 5};
    printVector(s.finalPrices(prices2));
    vector<int> prices3 = {10, 1, 1, 6};
    printVector(s.finalPrices(prices3));
	return 0;
}
