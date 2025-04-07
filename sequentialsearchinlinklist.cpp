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

// Singly Linked List ADT
class LinkedListADT {
private:
    Node* head;

public:
    // Constructor to initialize an empty linked list
    LinkedListADT() {
        head = NULL;
    }

    // Function to insert at the head of the linked list
    void insertAtHead(int val) {
        Node* new_node = new Node(val);
        new_node->next = head;
        head = new_node;
    }

    // Function to display the linked list
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->val << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Linear Search Function (Your Way)
    int linearSearch(int n) {
        Node* temp = head;
        int pos = 1;  // 1-based index

        while (temp != NULL) {
            if (temp->val == n) {
                return pos;  // Return position
            }
            temp = temp->next;
            pos++;
        }

        return -1;  // Not found
    }
};

int main() {
    LinkedListADT listADT;  // Create Linked List ADT object

    // Insert elements (Your Way: Inserting at Head)
    listADT.insertAtHead(7);
    listADT.insertAtHead(5);
    listADT.insertAtHead(34);
    listADT.insertAtHead(22);
    listADT.insertAtHead(1);

    // Print the linked list before searching
    cout << "Linked List: ";
    listADT.display();

    // Search for an element
    int num;
    cout << "Please enter an element to search: ";
    cin >> num;

    int result = listADT.linearSearch(num);

    if (result != -1) {
        cout << "Element found at position: " << result << endl;
    } else {
        cout << "No Element Found" << endl;
    }

    return 0;
}

