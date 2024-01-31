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
    // Inserting 0 at the beginning
    temp = one;
    head = one;
    struct Node* new1 = new Node();
    new1->data = 0;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = new1;
    new1->next = head;
    head = new1;

    cout << "\nUpdated Circular linked list" << endl;

    temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
}