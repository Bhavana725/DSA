#include <iostream>

// Node class represents a node in the linked list
class Node {
public:
    int data;
    Node* next;

    // Constructor to initialize a node
    Node(int value) : data(value), next(nullptr) {}
};

// Function to insert a node at the beginning of a linked list
Node* insertAtBeginning(Node* head, int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    return newNode;
}

// Function to perform insertion sort on a linked list
Node* insertionSort(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    Node* sorted = nullptr;
    Node* current = head;

    while (current != nullptr) {
        Node* next = current->next;
        sorted = insertAtBeginning(sorted, current->data);
        current = next;
    }

    return sorted;
}

// Function to perform bucket sort
void bucketSort(int arr[], int size) {
    const int bucketCount = 10;  // Number of buckets
    Node* buckets[bucketCount] = {nullptr};  // Array of bucket heads

    // Put array elements into buckets
    for (int i = 0; i < size; ++i) {
        int bucketIndex = arr[i] / bucketCount;
        buckets[bucketIndex] = insertAtBeginning(buckets[bucketIndex], arr[i]);
    }

    // Sort each bucket using insertion sort
    for (int i = 0; i < bucketCount; ++i) {
        buckets[i] = insertionSort(buckets[i]);
    }

    // Concatenate the sorted buckets to get the final sorted array
    int index = 0;
    for (int i = 0; i < bucketCount; ++i) {
        Node* current = buckets[i];
        while (current != nullptr) {
            arr[index++] = current->data;
            Node* temp = current;
            current = current->next;
            delete temp;  // Free memory allocated for the node
        }
    }
}

// Function to display the elements of an array
void displayArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int arr[] = {56, 32, 89, 12, 45, 67, 23, 91, 53};
    int size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original array: ";
    displayArray(arr, size);

    bucketSort(arr, size);

    std::cout << "Sorted array: ";
    displayArray(arr, size);

    return 0;
}
