#include <cassert>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        for (queue<int> q{{start}}; !q.empty();) {
            const int index = q.front(); q.pop();
            if (!arr[index]) return true;
            const int value = arr[index];
            arr[index] = -1;
            for (const int next : {index + value, index - value}) { if (next >= 0 && next < static_cast<int>(arr.size()) && arr[next] != -1) q.push(next); }
        }
        return false;
    }
};

int main()
{
    Solution s;
    vector<int> arr1 = {4, 2, 3, 0, 3, 1, 2};
    assert(s.canReach(arr1, 5));
    vector<int> arr2 = {4, 2, 3, 0, 3, 1, 2};
    assert(s.canReach(arr2, 0));
    vector<int> arr3 = {3, 0, 2, 1, 2};
    assert(!s.canReach(arr3, 2));
    return 0;
}
