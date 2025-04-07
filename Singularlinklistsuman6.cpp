#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    // Constructor
    Node(int data) {
        val = data;
        next = NULL;
    }
};

// Function to insert at the head of the linked list
void insertAtHead(Node*& head, int val) {
    Node* new_node = new Node(val);
    new_node->next = head;
    head = new_node;
}

// Function to insert at a specific position
void insertAtPosition(Node*& head, int val, int pos) {
    if (pos == 0) {
        insertAtHead(head, val);
        return;
    }

    Node* new_node = new Node(val);
    Node* temp = head;
    int cur_pos = 0;

    // Traverse to the position before where we want to insert
    while (temp != NULL && cur_pos < pos - 1) {
        temp = temp->next;
        cur_pos++;
    }

    // Insert the new node at the correct position
    new_node->next = temp->next;
    temp->next = new_node;
}

// Function to delete the head node
void deleteAtHead(Node*& head) {
    if (head == NULL) { // Check if list is already empty
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

// Function to delete a node at a given position (without checking if NULL)
void deleteAtPosition(Node*& head, int pos) {
    if (pos == 0) {
        deleteAtHead(head);
        return;
    }

    int current_pos = 0;
    Node* prev = head;

    // Traverse to the position before the one we want to delete
    while (current_pos != pos - 1) {
        prev = prev->next;
        current_pos++;
    }

    // Now prev is at pos-1, delete the node at pos
    Node* temp = prev->next;
    prev->next = prev->next->next;  // Remove node at pos
    delete temp;  // Use delete instead of free
}

void deleteAtTail(Node * head){
	Node * second_last=head;
	while(second_last->next->next!=NULL){
		second_last=second_last->next;
	}
	//now second last point to second last node
	Node* temp=second_last->next;
	second_last->next=NULL;
	delete temp;
}

// Function to display the linked list
void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->val << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = NULL;

    insertAtHead(head, 2);
    insertAtHead(head, 5);
    insertAtHead(head, 8);

    display(head); // Output: 8->5->2->NULL

    insertAtPosition(head, 25, 2); // Insert 25 at position 2
    display(head); // Output: 8->5->25->2->NULL

    deleteAtPosition(head, 2); // Delete node at position 2
    display(head); // Output: 8->5->2->NULL

    deleteAtPosition(head, 10); // Test: Deleting an invalid position (No effect)
    display(head); // Output remains unchanged
deleteAtTail(head);
display(head);
    return 0;
}

