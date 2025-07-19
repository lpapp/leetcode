#include <iostream>
#include <limits>
#include <stack>

using namespace std;

class MinStack {
public:
    stack<int> s1;
    stack<int> s2;
    MinStack() = default;
    
    void push(int val) {
        if (val <= getMin()) s2.push(val);
        s1.push(val);
    }
    
    void pop() {
        if (int val = s1.top(); val == getMin()) s2.pop();
        s1.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.empty() ? numeric_limits<int>::max() : s2.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main()
{
    MinStack* obj = new MinStack();
    obj->push(5);
    obj->pop();
    cout << obj->top() << endl;
    cout << obj->getMin() << endl;
    return 0;
}
