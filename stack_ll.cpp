#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    bool isEmpty() {
        return (top == nullptr);
    }

    void push(int data) {
        Node* newNode = new Node(data);
        newNode->next = top;
        top = newNode;
        std::cout << "Pushed element: " << data << std::endl;
    }

    void pop() {
        if (isEmpty()) {
            std::cout << "Stack Underflow: Cannot pop element, stack is empty." << std::endl;
            return;
        }

        Node* temp = top;
        int poppedElement = temp->data;
        top = top->next;
        delete temp;
        std::cout << "Popped element: " << poppedElement << std::endl;
    }

    int peek() {
        if (isEmpty()) {
            std::cout << "Stack is empty." << std::endl;
            return -1;
        }

        return top->data;
    }
};

int main() {
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "Top element: " << stack.peek() << std::endl;

    stack.pop();
    stack.pop();
    stack.pop();

    std::cout << "Top element: " << stack.peek() << std::endl;

    return 0;
}
