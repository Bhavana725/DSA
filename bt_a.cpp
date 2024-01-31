#include <iostream>
#include <climits>

void printArrayBinaryTree(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] != INT_MIN) {
            std::cout << arr[i] << " ";
        } else {
            std::cout << "- ";
        }
    }
    std::cout << std::endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7}; // Example array representing a binary tree

    int size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Array representation of the binary tree: ";
    printArrayBinaryTree(arr, size);

    return 0;
}
