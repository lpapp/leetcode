#include <iostream>
#include <vector>

using namespace std;

class MyCircularQueue {
    size_t front{0}, size{0}, capacity;
    vector<int> data;
public:
    MyCircularQueue(int k): capacity(k), data(vector<int>(k)) {}
    bool enQueue(int value) { if (isFull()) return false; data[(front + size++) % capacity] = value; return true; }
    bool deQueue() { if (isEmpty()) return false; front = (front + 1) % capacity; --size; return true; }
    int Front() { return isEmpty() ? -1 : data[front]; }
    int Rear() { return isEmpty() ? -1 : data[(front + size - 1) % capacity]; }
    bool isEmpty() { return size == 0; }
    bool isFull() { return size == capacity; }
};

int main()
{
    MyCircularQueue* myCircularQueue = new MyCircularQueue(3);
    cout << myCircularQueue->enQueue(1) << endl;
    cout << myCircularQueue->enQueue(2) << endl;
    cout << myCircularQueue->enQueue(3) << endl;
    cout << myCircularQueue->enQueue(4) << endl;
    cout << myCircularQueue->Rear() << endl;
    cout << myCircularQueue->isFull() << endl;
    cout << myCircularQueue->deQueue() << endl;
    cout << myCircularQueue->enQueue(4) << endl;
    cout << myCircularQueue->Rear() << endl;
    return 0;
}
