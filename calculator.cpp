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
    int sum = 0;
    for (int i = 0; i < expr.length(); i++) {
        char ch = expr[i];
        if (ch == '/' || ch == '*' || ch == '+' || ch == '-') {
            cout << "OPERATOR FOUND: " << ch << "\n";
            int int2 = stack.pop();
            int int1 = stack.pop();
            cout << "INT 1 IS " << int1 << "\n";
            cout << "INT 2 IS " << int2 << "\n";
            switch (ch) {
                case '+':
                    sum = int1 + int2;
                    break;
                case '-':
                    sum = int1 - int2;
                    break;
                case '*':
                    sum = int1 * int2;
                    break;
                case '/':
                    sum = int1 / int2;
                    break;
            }
            stack.push(sum);
            cout << "SUM IS " << sum << "\n";
        }
        /* The code below is to figure out when the digits should be concatenated into a number */
        if (ch == ' ' && digits > 0) {
            std::list<int> digit;
            for (int j = 0; j < digits; j++) {
                digit.push_back(stack.pop());
            }
            string number;
            for (int k = 0; k < digits; k++) {
                int temp = digit.back();
                digit.pop_back();
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

    return sum;
}

/* the value of 'expr' is what should be altered by the calculator as this is the string to be calculated */
/* this is currently just at a default value */
int main() {
    std::string expr = "10 3 +";
    int result = eval(expr);
    cout << result;
}