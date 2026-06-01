#include <cassert>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        for (int i = 0, n = profits.size(); i < n; ++i) minHeap.push({capital[i], profits[i]});
        for (priority_queue<int> maxHeap; k--; w += maxHeap.top(), maxHeap.pop()) {
            for (; !minHeap.empty() && minHeap.top().first <= w; maxHeap.push(minHeap.top().second), minHeap.pop());
            if (maxHeap.empty()) break;
        }
        return w;      
    }
};

int main()
{
	Solution s;
    vector<int> profits1 = {1, 2, 3};
	vector<int> capital1 = {0, 1, 1};
    assert(s.findMaximizedCapital(2, 0, profits1, capital1) == 4);
    vector<int> profits2 = {1, 2, 3};
	vector<int> capital2 = {0, 1, 2};
    assert(s.findMaximizedCapital(3, 0, profits2, capital2) == 6);
	return 0;
}
