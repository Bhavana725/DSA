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

// BinaryTree class represents the binary tree
class BinaryTree {
private:
    Node* root;

    // Helper function for inorder traversal
    void inorderHelper(Node* node) {
        if (node != nullptr) {
            // Traverse the left subtree
            inorderHelper(node->left);

            // Visit the current node
            std::cout << node->data << " ";

            // Traverse the right subtree
            inorderHelper(node->right);
        }
    }

public:
    // Constructor to initialize an empty binary tree
    BinaryTree() : root(nullptr) {}

    // Function to perform inorder traversal of the binary tree
    void inorder() {
        std::cout << "Inorder traversal: ";
        inorderHelper(root);
        std::cout << std::endl;
    }

    // Function to insert a node into the binary tree
    void insert(int value) {
        root = insertHelper(root, value);
    }

private:
    // Helper function to insert a node into the binary tree
    Node* insertHelper(Node* node, int value) {
        // If the tree is empty, create a new node
        if (node == nullptr) {
            return new Node(value);
        }

        // Otherwise, recursively insert into the left or right subtree
        if (value < node->data) {
            node->left = insertHelper(node->left, value);
        } else if (value > node->data) {
            node->right = insertHelper(node->right, value);
        }

        return node;
    }
};

int main() {
    // Create a binary tree
    BinaryTree tree;

    // Insert elements into the tree
    tree.insert(3);
    tree.insert(1);
    tree.insert(5);
    tree.insert(2);
    tree.insert(4);

    // Perform inorder traversal
    tree.inorder();

    return 0;
}
