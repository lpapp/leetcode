#include <iostream>
#include <stack>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

class MyStack {
    queue<int> result, buffer;
public:
    MyStack() = default;
    void push(int x) {
        for (buffer.push(x); !result.empty(); result.pop()) buffer.push(result.front());
        swap(result, buffer);   
    }
    
    int pop() { const int top = result.front(); result.pop(); return top; }
    int top() { return result.front(); }
    bool empty() { return result.empty(); }
};

int main()
{
	MyStack* myStack = new MyStack();
	myStack->push(1);
	myStack->push(2);
	cout << myStack->top() << endl;
	cout << myStack->pop() << endl;
	cout << myStack->empty() << endl;
	return 0;
}
