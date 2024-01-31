#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = nullptr;  // Initially, the list is empty

void insertAtEnd(int data) {
    Node* newNode = new Node();  // Create a new node
    newNode->data = data;
    newNode->next = nullptr;     // Last node's next pointer points to null

    if (head == nullptr) {  // If list is empty, make new node as head
        head = newNode;
        newNode->prev = nullptr;  // Head's previous pointer points to null
    } else {
        Node* temp = head;
        // Traverse to the last node
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;  // Link new node's previous pointer to the last node
    }
}

void printList() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    insertAtEnd(40);
    insertAtEnd(20);
    insertAtEnd(30);

    cout << "Doubly linked list: ";
    printList(); 

    return 0;
}
