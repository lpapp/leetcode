#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
    stack<int> stackNewest, stackOldest;
public:
    MyQueue() = default;
    
    void push(int x) {
        // Push onto stackNewest, which always has the newest elements on top.
        stackNewest.push(x);
    }
    
    int pop() {
        const int val = peek();
        stackOldest.pop(); // Retrieve the oldest item.
        return val;
    }
    
    int peek() {
        shiftStacks(); // Ensure that stackOldest has the current elements.
        return stackOldest.top(); // Retrieve the oldest item.
    }
    
    bool empty() {
        return stackNewest.empty() && stackOldest.empty();
    }

    void shiftStacks() {
        if (stackOldest.empty()) {
            while (!stackNewest.empty()) {
                stackOldest.push(stackNewest.top());
                stackNewest.pop();
            }
        }
    }
};

int main()
{
    MyQueue* obj = new MyQueue();
    obj->push(5);
    cout << obj->pop() << endl;
    cout << obj->peek() << endl;
    cout << obj->empty() << endl;
    return 0;
}
