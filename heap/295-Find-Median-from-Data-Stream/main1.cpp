#include <cassert>
#include <functional>
#include <queue>
#include <vector>

using namespace std;

class MedianFinder {
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
public:
    MedianFinder() = default;
    void addNum(int num) { maxHeap.push(num); minHeap.push(maxHeap.top()); maxHeap.pop(); if (minHeap.size() > maxHeap.size() + 1) { maxHeap.push(minHeap.top()); minHeap.pop(); } }
    double findMedian() { return minHeap.size() == maxHeap.size() ? (minHeap.top() + maxHeap.top()) / 2.0 : minHeap.top(); }
};

int main()
{
    MedianFinder medianFinder;
    medianFinder.addNum(1);
    medianFinder.addNum(2);
    assert(medianFinder.findMedian() == 1.5);
    medianFinder.addNum(3);
    assert(medianFinder.findMedian() == 2.0);
    return 0;
}
