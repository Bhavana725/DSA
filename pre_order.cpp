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

// Function to perform preorder traversal
void preorderTraversal(Node* root) {
    if (root != nullptr) {
        // Process the current node
        std::cout << root->data << " ";

        // Recursively traverse the left subtree
        preorderTraversal(root->left);

        // Recursively traverse the right subtree
        preorderTraversal(root->right);
    }
}

int main() {
    // Create a simple binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // Perform preorder traversal and print the nodes
    std::cout << "Preorder traversal: ";
    preorderTraversal(root);

    // Free dynamically allocated memory (cleanup)
    // In a real-world scenario, you may use smart pointers or a custom cleanup function
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root;

    return 0;
}
