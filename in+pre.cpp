#include <iostream>
#include <stack>

using namespace std;

// Function to check if the character is an operand
bool isOperand(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

// Function to get the precedence of an operator
int precedence(char op) {
    if (op == '^') return 3;
    else if (op == '*' || op == '/') return 2;
    else if (op == '+' || op == '-') return 1;
    else return -1;
}

// Function to convert infix expression to postfix expression
string infixToPrefix(const string& infix) {
    stack<char> operators;
    stack<string> operands;

    for (int i = 0; i < infix.length(); ++i) {
        char current = infix[i];

        if (isOperand(current)) {
            operands.push(string(1, current));
        } else if (current == '(') {
            operators.push(current);
        } else if (current == ')') {
            while (!operators.empty() && operators.top() != '(') {
                string operand2 = operands.top();
                operands.pop();

                string operand1 = operands.top();
                operands.pop();

                char op = operators.top();
                operators.pop();

                operands.push(op + operand1 + operand2);
            }
            operators.pop(); // Pop '('
        } else { // Operator
            while (!operators.empty() && precedence(current) <= precedence(operators.top())) {
                string operand2 = operands.top();
                operands.pop();

                string operand1 = operands.top();
                operands.pop();

                char op = operators.top();
                operators.pop();

                operands.push(op + operand1 + operand2);
            }

            operators.push(current);
        }
    }

    while (!operators.empty()) {
        string operand2 = operands.top();
        operands.pop();

        string operand1 = operands.top();
        operands.pop();

        char op = operators.top();
        operators.pop();

        operands.push(op + operand1 + operand2);
    }

    return operands.top();
}

int main() {
    string infixExpression = "a+b*c-(d/e+f*g*h)";

    cout << "Infix Expression: " << infixExpression << endl;

    string prefixExpression = infixToPrefix(infixExpression);

    cout << "Prefix Expression: " << prefixExpression << endl;

    return 0;
}
