#ifndef STACK_H
#define STACK_H
#define SIZE 100

class STACK {
    private:
        int num[SIZE];
        int top;
    public:
        STACK();
        int push(int);
        int pop();
        int isEmpty();
        int isFull();
        int size();
};

#endif /* STACK_H */