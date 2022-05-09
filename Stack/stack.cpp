#include "stack.h"

STACK::STACK() {
    top=-1;
}

int STACK::isEmpty() {
    if(top==-1)
        return 1;
    else
        return 0;
}

int STACK::isFull() {
    if(top==(SIZE-1))
        return 1;
    else
        return 0;
}

int STACK::push(int i) {
    if(isFull()) {
        return -304;
    }
    ++top;
    num[top]=i;
    return i;
}

int STACK::pop() {
    int temp;
    if(isEmpty())
        return -304;
    temp=num[top];
    --top;
    return temp;
}

int STACK::size() {
    return top+1;
}