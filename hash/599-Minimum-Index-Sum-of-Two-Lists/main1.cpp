#include <iostream>
#include <limits>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, size_t> hash;
        for (size_t i = 0; i < list2.size(); ++i) hash[list2[i]] = i;
        vector<string> result;
        int minIndexSum = numeric_limits<int>::max();
        for (size_t i = 0; i < list1.size(); ++i) {
            if (!hash.contains(list1[i])) continue;
            const size_t j = hash[list1[i]];
            const int indexSum = i + j;
            if (indexSum < minIndexSum) {
                minIndexSum = indexSum;
                result.clear();
                result.push_back(list1[i]);
            } 
            else if (indexSum == minIndexSum) {
                result.push_back(list1[i]);
            }
        }
        return result;       
    }
};

void printVector(vector<string> input)
{
    for (const string& item : input) cout << item << ", ";
    cout << endl;
}

int main()
{
	Solution s;
    vector<string> list11 = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
    vector<string> list21 = {"Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"};
    printVector(s.findRestaurant(list11, list21));

    vector<string> list12 = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
    vector<string> list22 = {"KFC", "Shogun", "Burger King"};
    printVector(s.findRestaurant(list12, list22));

    vector<string> list13 = {"happy", "sad", "good"};
    vector<string> list23 = {"sad", "happy", "good"};
    printVector(s.findRestaurant(list13, list23));
	return 0;
}
