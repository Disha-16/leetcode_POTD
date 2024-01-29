#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> stackIn, stackOut;

    // Transfer all elements from stackIn to stackOut
    void transferInToOut() {
        while (!stackIn.empty()) {
            stackOut.push(stackIn.top());
            stackIn.pop();
        }
    }

public:
    MyQueue() {}

    void push(int x) {
        stackIn.push(x);
    }

    int pop() {
        if (stackOut.empty()) {
            transferInToOut();
        }
        int topElement = stackOut.top();
        stackOut.pop();
        return topElement;
    }

    int peek() {
        if (stackOut.empty()) {
            transferInToOut();
        }
        return stackOut.top();
    }

    bool empty() {
        return stackIn.empty() && stackOut.empty();
    }
};
