#include <iostream>

// Node class represents a node in the doubly linked list
class Node {
public:
    int data;
    Node* prev;
    Node* next;

    // Constructor to initialize a node
    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

// DoublyLinkedList class represents the doubly linked list
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    // Constructor to initialize an empty doubly linked list
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Function to insert a node at the middle of the doubly linked list
    void insertAtMiddle(int value) {
        Node* newNode = new Node(value);

        // If the list is empty, make the new node the head and tail
        if (head == nullptr) {
            head = tail = newNode;
            return;
        }

        // Traverse the list to find the middle
        Node* slow = head;
        Node* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Insert the new node at the middle
        newNode->prev = slow;
        newNode->next = slow->next;

        if (slow->next != nullptr) {
            slow->next->prev = newNode;
        } else {
            // If the list has an odd number of nodes, update the tail
            tail = newNode;
        }

        slow->next = newNode;
    }

    // Function to display the elements of the doubly linked list
    void display() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    // Create a doubly linked list
    DoublyLinkedList myList;

    // Insert elements at the middle
    myList.insertAtMiddle(1);
    myList.insertAtMiddle(2);
    myList.insertAtMiddle(3);
    myList.insertAtMiddle(4);

    // Display the doubly linked list
    std::cout << "Doubly Linked List: ";
    myList.display();

    return 0;
}
