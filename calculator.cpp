#include "Stack/stack.h"
#include "Stack/stack.cpp"
#include <iostream>

using namespace std;

int eval(std::string expr) {
    // take string & convert to ints
    // push numbers to stack until operator is found
    // calculate the result and push result to stack

    STACK stack;

    for(int i = 0; i < expr.length(); i++) {
        char ch = expr[i];
        if(ch == '/' || ch == '*' || ch == '+' || ch == '-') {
            cout << "OPERATOR FOUND: " << ch << "\n";
            int sum;
            int int1 = stack.pop();
            cout << "INT 1 IS " << int1 << "\n";
            int int2 = stack.pop();
            cout << "INT 2 IS " << int2 << "\n";
            switch(ch) {
                case '+': sum = int2 + int1;
                case '-': sum = int2 - int1;
                case '*': sum = int2 * int1;
                case '/': sum = int2 / int1;
                stack.push(sum);
                cout << "SUM IS " << sum << "\n";
            }
        }
        else {
            cout << "NUMBER FOUND: " << (int)ch << "\n";
            stack.push((int)ch);
        }
    }

    cout << "GETTING FINAL SUM\n";
    for(int i = 0; i < stack.size(); i++) {
        if(stack.size() > 2) {
            stack.push(stack.pop() + stack.pop());
        }
        else {
            break;
        }
    }

    return stack.pop();
}

int main() {
    std::string expr = "21+";
    int result = eval(expr);
    cout << result;
}