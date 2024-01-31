#include <iostream>

// Node class represents a node in the binary tree
class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a node
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// BinarySearchTree class represents the binary search tree
class BinaryTree {
private:
    Node* root;

public:
    // Constructor to initialize an empty binary tree
    BinaryTree() : root(nullptr) {}

    // Function to insert a value into the binary tree
    Node* insert(Node* current, int value) {
        if (current == nullptr) {
            return new Node(value);
        }

        if (value < current->data) {
            current->left = insert(current->left, value);
        } else if (value > current->data) {
            current->right = insert(current->right, value);
        }

        return current;
    }

    // Public function to insert a value into the binary tree
    void insert(int value) {
        root = insert(root, value);
    }

    // Function to traverse the binary tree in postorder
    void postorder(Node* current) {
        if (current != nullptr) {
            postorder(current->left);
            postorder(current->right);
            std::cout << current->data << " ";
        }
    }

    // Public function to perform postorder traversal
    void postorderTraversal() {
        postorder(root);
        std::cout << std::endl;
    }
};

int main() {
    // Create a binary tree
    BinaryTree myTree;

    // Insert elements into the tree
    myTree.insert(5);
    myTree.insert(3);
    myTree.insert(7);
    myTree.insert(2);
    myTree.insert(4);
    myTree.insert(6);
    myTree.insert(8);

    // Perform postorder traversal and display the elements
    std::cout << "Postorder Traversal: ";
    myTree.postorderTraversal();

    return 0;
}
