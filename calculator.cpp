#include "Stack/stack.h"
#include "Stack/stack.cpp"
#include <iostream>
#include <string>
#include <list>

using namespace std;

int eval(std::string expr) {
    // take string & convert to ints
    // push numbers to stack until operator is found
    // calculate the result and push result to stack

    STACK stack;

    cout << "expr length: " << expr.length() << "\n";

    int digits = 0;
    for (int i = 0; i < expr.length(); i++) {
        char ch = expr[i];
        if (ch == '/' || ch == '*' || ch == '+' || ch == '-') {
            cout << "OPERATOR FOUND: " << ch << "\n";
            int sum = 0;
            int int1 = stack.pop();
            cout << "INT 1 IS " << int1 << "\n";
            int int2 = stack.pop();
            cout << "INT 2 IS " << int2 << "\n";
            switch (ch) {
                case '+':
                    sum = int2 + int1;
                    break;
                case '-':
                    sum = int2 - int1;
                    break;
                case '*': 
                    sum = int2 * int1;
                    break;
                case '/': 
                    sum = int2 / int1;
                    break;
            }
            stack.push(sum);
            cout << "SUM IS " << sum << "\n";
        }
        else {
            if(ch == ' ' && digits > 0) {
                std::list<int> digit;
                for(int j = 0; j < digits; j++) {
                    digit.push_back(stack.pop());
                }
                string number;
                for(int k = 0; k < digits; k++) {
                    int temp = digit.front();
                    digit.pop_front();
                    number = number + std::to_string(temp);
                }
                stack.push(stoi(number));
                digits = 0;
            }
            else {
                cout << "NUMBER FOUND: " << ch << "\n";
                stack.push(atoi(&ch));
                digits++;
            }
        }
    }

    cout << "GETTING FINAL SUM\n";
    for (int i = 0; i < stack.size(); i++) {
        if (stack.size() > 2) {
            stack.push(stack.pop() + stack.pop());
        }
        else {
            break;
        }
    }

    return stack.pop();
}

int main() {
    std::string expr = "22 11 +";
    int result = eval(expr);
    cout << result;
}