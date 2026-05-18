#include <cassert>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int, vector<int>> hash;
        const int arraySize = arr.size();
        for (int i = 0; i < arraySize; ++i) hash[arr[i]].push_back(i);
        vector<bool> visited(arraySize); visited[0] = true;
        queue<int> q{{0}};
        for (int res = 0;; ++res) {
            for (int k = 0, size = q.size(); k < size; ++k) {
                const int index = q.front(); q.pop();
                if (index == arraySize - 1) return res;
                for (const int next : hash[arr[index]]) { if (!visited[next]) { visited[next] = true; q.push(next); } }
                hash[arr[index]].clear();
                for (const int next : {index - 1, index + 1}) { if (next >= 0 && next < arraySize && !visited[next]) { visited[next] = true; q.push(next); } }
            }
        }
    }
};

int main()
{
    Solution s;
    vector<int> arr1 = {100, -23, -23, 404, 100, 23, 23, 23, 3, 404};
    assert(s.minJumps(arr1) == 3);
    vector<int> arr2 = {7};
    assert(s.minJumps(arr2) == 0);
    vector<int> arr3 = {7, 6, 9, 6, 9, 6, 9, 7};
    assert(s.minJumps(arr3) == 1);
    return 0;
}
