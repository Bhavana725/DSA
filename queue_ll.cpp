#include <iostream>

namespace Queue {
    // Node class represents a node in the queue
    class Node {
    public:
        int data;
        Node* next;

        // Constructor to initialize a node
        Node(int value) : data(value), next(nullptr) {}
    };

    // Queue class represents the Queue ADT
    class LinkedQueue {
    private:
        Node* front;
        Node* rear;

    public:
        // Constructor to initialize an empty queue
        LinkedQueue() : front(nullptr), rear(nullptr) {}

        // Function to check if the queue is empty
        bool isEmpty() {
            return front == nullptr;
        }

        // Function to enqueue (insert) an element to the queue
        void enqueue(int value) {
            Node* newNode = new Node(value);
            if (isEmpty()) {
                front = rear = newNode;
            } else {
                rear->next = newNode;
                rear = newNode;
            }
        }

        // Function to dequeue (remove) an element from the queue
        void dequeue() {
            if (isEmpty()) {
                std::cout << "Queue is empty. Cannot dequeue." << std::endl;
                return;
            }

            Node* temp = front;
            front = front->next;

            // If the queue becomes empty after dequeue, update rear as well
            if (front == nullptr) {
                rear = nullptr;
            }

            delete temp;
        }

        // Function to get the front element of the queue
        int frontElement() {
            if (isEmpty()) {
                std::cerr << "Queue is empty. No front element." << std::endl;
                return -1; // Return a default value or handle the situation accordingly
            }

            return front->data;
        }

        // Function to display the elements of the queue
        void display() {
            if (isEmpty()) {
                std::cout << "Queue is empty." << std::endl;
                return;
            }

            Node* current = front;
            while (current != nullptr) {
                std::cout << current->data << " ";
                current = current->next;
            }
            std::cout << std::endl;
        }
    };
}

int main() {
    using namespace Queue;

    // Create a linked queue
    LinkedQueue myQueue;

    // Enqueue elements
    myQueue.enqueue(1);
    myQueue.enqueue(2);
    myQueue.enqueue(3);

    // Display the queue
    std::cout << "Queue elements: ";
    myQueue.display();

    // Dequeue an element
    myQueue.dequeue();

    // Display the queue after dequeue
    std::cout << "Queue elements after dequeue: ";
    myQueue.display();

    // Get the front element
    std::cout << "Front element: " << myQueue.frontElement() << std::endl;

    return 0;
}
