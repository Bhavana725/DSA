#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};

int main() {
    struct Node* one = new Node();   
    struct Node* two = new Node();
    struct Node* three = new Node();
    struct Node* last;

    one->data = 10;
    two->data = 20;
    three->data = 30;
    one->next = two;
    two->next = three;
    three->next = one;

    cout << "Original Circular linked list" << endl;

    struct Node* temp;
    struct Node* head;

    temp = one;
    head = one;

    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

    // Inserting in the middle
    int key = 35;
    struct Node* new3 = new Node();
    new3->data = key;

    temp = one;
    while (temp->next != head && temp->next->data < key) {
        temp = temp->next;
    }

    new3->next = temp->next;
    temp->next = new3;

    cout << "\nUpdated Circular linked list after inserting in the middle" << endl;

    temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

    return 0;
}
