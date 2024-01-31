#include <iostream>
#include <stack>

using namespace std;

// Function to check if the character is an operand
bool isOperand(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

// Function to convert postfix expression to prefix expression
string postfixToPrefix(const string& postfix) {
    stack<string> stk;

    for (char ch : postfix) {
        if (isOperand(ch)) {
            string operand(1, ch);
            stk.push(operand);
        } else {
            string operand2 = stk.top();
            stk.pop();

            string operand1 = stk.top();
            stk.pop();

            string expression = ch + operand1 + operand2;
            stk.push(expression);
        }
    }

    return stk.top();
}

int main() {
    string postfixExpression;

    // Input postfix expression
    cout << "Enter the postfix expression: ";
    cin >> postfixExpression;

    // Convert to prefix
    string prefixExpression = postfixToPrefix(postfixExpression);

    // Output the result
    cout << "Prefix expression: " << prefixExpression << endl;

    return 0;
}
