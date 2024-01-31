#include <iostream>

const int MAX_SIZE = 100;

namespace Stack {
    int arr[MAX_SIZE];
    int top = -1;

    bool isEmpty() {
        return (top == -1);
    }

    bool isFull() {
        return (top == MAX_SIZE - 1);
    }

    void push(int data) {
        if (isFull()) {
            std::cout << "Stack Overflow: Cannot push element, stack is full." << std::endl;
            return;
        }

        top++;
        arr[top] = data;
        std::cout << "Pushed element: " << data << std::endl;
    }

    void pop() {
        if (isEmpty()) {
            std::cout << "Stack Underflow: Cannot pop element, stack is empty." << std::endl;
            return;
        }

        int poppedElement = arr[top];
        top--;
        std::cout << "Popped element: " << poppedElement << std::endl;
    }

    int peek() {
        if (isEmpty()) {
            std::cout << "Stack is empty." << std::endl;
            return -1;
        }

        return arr[top];
    }
}

int main() {
    using namespace Stack;

    push(10);
    push(20);
    push(30);

    std::cout << "Top element: " << peek() << std::endl;

    pop();
    pop();
    pop();

    std::cout << "Top element: " << peek() << std::endl;

    return 0;
}
