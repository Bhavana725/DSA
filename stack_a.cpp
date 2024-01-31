#include <iostream>

namespace Stack {
    const int MAX_SIZE = 100;
    
    // Stack class represents the Stack ADT
    class ArrayStack {
    private:
        int arr[MAX_SIZE];
        int top;

    public:
        // Constructor to initialize an empty stack
        ArrayStack() : top(-1) {}

        // Function to check if the stack is empty
        bool isEmpty() {
            return (top == -1);
        }

        // Function to check if the stack is full
        bool isFull() {
            return (top == MAX_SIZE - 1);
        }

        // Function to push an element onto the stack
        void push(int data) {
            if (isFull()) {
                std::cout << "Stack Overflow: Cannot push element, stack is full." << std::endl;
                return;
            }

            top++;
            arr[top] = data;
            std::cout << "Pushed element: " << data << std::endl;
        }

        // Function to pop an element from the stack
        void pop() {
            if (isEmpty()) {
                std::cout << "Stack Underflow: Cannot pop element, stack is empty." << std::endl;
                return;
            }

            int poppedElement = arr[top];
            top--;
            std::cout << "Popped element: " << poppedElement << std::endl;
        }

        // Function to get the top element of the stack
        int topElement() {
            if (isEmpty()) {
                std::cerr << "Stack is empty." << std::endl;
                return -1; // Return a default value or handle the situation accordingly
            }

            return arr[top];
        }

        // Function to display the elements of the stack
        void display() {
            if (isEmpty()) {
                std::cout << "Stack is empty." << std::endl;
                return;
            }

            std::cout << "Stack elements: ";
            for (int i = 0; i <= top; ++i) {
                std::cout << arr[i] << " ";
            }
            std::cout << std::endl;
        }
    };
}

int main() {
    using namespace Stack;

    // Create an array stack
    ArrayStack myStack;

    // Push elements
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    // Display the stack
    myStack.display();

    // Pop an element
    myStack.pop();

    // Display the stack after pop
    myStack.display();

    // Get the top element
    std::cout << "Top element: " << myStack.topElement() << std::endl;

    return 0;
}
