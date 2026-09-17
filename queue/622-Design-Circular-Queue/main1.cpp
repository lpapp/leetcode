#include <cassert>
#include <vector>

using namespace std;

class MyCircularQueue {
    int front = 0, size = 0, capacity;
    vector<int> data;
public:
    MyCircularQueue(int k) : capacity(k), data(k) {}
    bool enQueue(int value) { if (isFull()) return false; data[(front + size++) % capacity] = value; return true; }
    bool deQueue() { if (isEmpty()) return false; front = (front + 1) % capacity; --size; return true; }
    int Front() const { return isEmpty() ? -1 : data[front]; }
    int Rear() const { return isEmpty() ? -1 : data[(front + size - 1) % capacity]; }
    bool isEmpty() const { return size == 0; }
    bool isFull() const { return size == capacity; }
};

int main()
{
    MyCircularQueue myCircularQueue(3);
    assert(myCircularQueue.enQueue(1));
    assert(myCircularQueue.enQueue(2));
    assert(myCircularQueue.enQueue(3));
    assert(!myCircularQueue.enQueue(4));
    assert(myCircularQueue.Rear() == 3);
    assert(myCircularQueue.isFull());
    assert(myCircularQueue.deQueue());
    assert(myCircularQueue.enQueue(4));
    assert(myCircularQueue.Rear() == 4);
    return 0;
}
