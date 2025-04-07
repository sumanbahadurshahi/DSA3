#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Function to search for a key in BST
Node* searchInBst(Node* root, int key) {
    if (root == NULL) {
        return NULL;
    }
    if (root->data == key) {
        return root;
    }
    if (root->data > key) {
        return searchInBst(root->left, key);
    }
    return searchInBst(root->right, key);
}

// Function to find the inorder successor (smallest node in right subtree)
Node* findMin(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to delete a node in BST
Node* deleteInBst(Node* root, int key) {
    if (root == NULL) {
        return NULL;
    }

    if (key < root->data) {
        root->left = deleteInBst(root->left, key);
    } else if (key > root->data) {
        root->right = deleteInBst(root->right, key);
    } else {
        // Case 1: Node with only one child or no child
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 2: Node with two children
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteInBst(root->right, temp->data);
    }
    return root;
}

int main() {
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->right = new Node(6);

    if (searchInBst(root, 5) == NULL) {
        cout << "Key does not exist" << endl;
    } else {
        cout << "Key exists" << endl;
    }

    // Deleting a node and checking again
    root = deleteInBst(root, 5);

    if (searchInBst(root, 5) == NULL) {
        cout << "Key deleted successfully" << endl;
    } else {
        cout << "Key still exists" << endl;
    }

    return 0;
}

