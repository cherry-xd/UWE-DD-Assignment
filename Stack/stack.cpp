#include "stack.h"
#include <iostream>

using namespace std;

STACK::STACK() {
    top = -1;
}

int STACK::isEmpty() {
    if (top == -1)
        return 1;
    else
        return 0;
}

int STACK::isFull() {
    if (top == (SIZE - 1))
        return 1;
    else
        return 0;
}

int STACK::push(int i) {
    if (isFull()) {
        cout << "STACK FULL ERROR -30424\n";
        // This is so we know if the stack has reached its limit
        return -30424;
    }
    ++top;
    num[top] = i;
    return i;
}

int STACK::pop() {
    int temp;
    if (isEmpty()) {
        cout << "STACK EMPTY ERROR -30425\n";
        // This error is so we know if the stack is empty
        return -30425;
    }
    temp = num[top];
    --top;
    return temp;
}

int STACK::size() {
    return top + 1;
}