#include <algorithm>
#include <iostream>

using namespace std;

class Solution {

public:
    // Method to calculate the maximum number of increasing groups
    int maxIncreasingGroups(vector<int>& usageLimits) {
        // Sort the usage limits in non-decreasing order
        sort(usageLimits.begin(), usageLimits.end());

        // Initialize the number of groups that can be formed
        int numberOfGroups = 0;

        // Initialize a sum variable to calculate the cumulative sum of elements
        long long sum = 0;

        // Iterate over each usage limit
        for (const int limit : usageLimits) {
            // Add the current limit to the cumulative sum
            sum += limit;

            // Check if after adding the current element, the sum becomes
            // greater than the number of groups we have so far.
            // If yes, it means we can form a new group with higher limit.
            if (sum > numberOfGroups) {
                // Increment the number of groups that can be formed
                ++numberOfGroups;
              
                // Decrease the sum by the number of groups since
                // we allocate each element of a group with a distinct size
                sum -= numberOfGroups;
            }
        }

        // Return the maximum number of increasing groups that can be formed
        return numberOfGroups;
    }
};

int main()
{
    Solution solution;
    vector<int> i1{1, 2, 5};
    cout << solution.maxIncreasingGroups(i1) << endl;

    vector<int> i2{2, 1, 2};
    cout << solution.maxIncreasingGroups(i2) << endl;

    vector<int> i3{1, 1};
    cout << solution.maxIncreasingGroups(i3) << endl;

    vector<int> i4{1, 2, 7};
    cout << solution.maxIncreasingGroups(i4) << endl;

    vector<int> i5{1, 2, 8, 9};
    cout << solution.maxIncreasingGroups(i5) << endl;

    vector<int> i6{1, 1, 8, 11, 11, 12, 12};
    cout << solution.maxIncreasingGroups(i6) << endl;

    vector<int> i7{4};
    cout << solution.maxIncreasingGroups(i7) << endl;

    vector<int> i8{0, 0};
    cout << solution.maxIncreasingGroups(i8) << endl;

    vector<int> i9{2, 5, 5, 6, 9, 5, 4, 6, 1, 6, 10, 2, 9, 9, 3, 2, 10, 3, 9, 7, 10, 6, 1, 1, 2, 1, 2, 7, 7, 8, 3, 8, 2, 7, 5, 3, 3, 10, 8, 6, 6, 9, 9, 6, 7, 2, 9, 6, 4, 8};
    cout << solution.maxIncreasingGroups(i9) << endl;

    return 0;
}
