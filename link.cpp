#include<iostream>
using namespace std;

class Node {
public:
    int val;
    Node *next;
    
    // Constructor
    Node(int data) {
        val = data;
        next = NULL;
    }

    // Display function to show the linked list
    void display(Node* head) {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->val << " -> ";  // Use 'val' instead of 'value'
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

// Global function to insert a node at the head of the linked list
void insertAthead(Node*& head, int val) {
    Node* new_node = new Node(val);
    new_node->next = head;
    head = new_node;
}

int main() {
    Node* head = NULL;  // Initialize an empty linked list

    insertAthead(head, 2);  // Insert a node with value 2
    insertAthead(head, 3);  // Insert a node with value 3
    insertAthead(head, 5);  // Insert a node with value 5

    // Display the linked list
    Node displayNode(0); // Create a dummy node to call the display method
    displayNode.display(head);

    return 0;
}

