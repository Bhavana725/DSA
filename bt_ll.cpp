#include <iostream>

// Structure for a node in the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Function to insert a node into the binary tree
Node* insertNode(Node* root, int data) {
    // If the tree is empty, create a new node and make it the root
    if (root == nullptr) {
        root = new Node(data);
        return root;
    }

    // Otherwise, recursively insert the node in the appropriate position
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }

    return root;
}

// Function to traverse the binary tree in inorder fashion
void inorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }

    inorderTraversal(root->left);
    std::cout << root->data << " ";
    inorderTraversal(root->right);
}

int main() {
    Node* root = nullptr;

    // Insert nodes into the binary tree
    root = insertNode(root, 4);
    root = insertNode(root, 2);
    root = insertNode(root, 6);
    root = insertNode(root, 1);
    root = insertNode(root, 3);
    root = insertNode(root, 5);
    root = insertNode(root, 7);

    // Traverse the binary tree in inorder fashion
    std::cout << "Inorder traversal of the binary tree: ";
    inorderTraversal(root);
    std::cout << std::endl;

    return 0;
}
