#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* prev;
    
    Node(int data) {
        val = data;
        next = NULL;
        prev = NULL;
    }
};

class DoublyCircularLinkedList {
public:
    Node* head;
    
    DoublyCircularLinkedList() {
        head = NULL;
    }
    
    void insertAtStart(int val) {
        Node* new_node = new Node(val);
        if (head == NULL) {
            head = new_node;
            new_node->next = head;
            new_node->prev = head;
            return;
        }

        Node* tail = head->prev; // Get the last node
        new_node->next = head;
        new_node->prev = tail;
        head->prev = new_node;
        tail->next = new_node;
        head = new_node;
    }
    
    void insertAtEnd(int val) {
        Node* new_node = new Node(val);
        if (head == NULL) {
            head = new_node;
            new_node->next = head;
            new_node->prev = head;
            return;
        }
        
        Node* tail = head->prev; // Get the last node
        tail->next = new_node;
        new_node->prev = tail;
        new_node->next = head;
        head->prev = new_node;
    }
    
    void deleteAtStart() {
        if (head == NULL) {
            return;
        }

        if (head->next == head) { // Only one node present
            delete head;
            head = NULL;
            return;
        }

        Node* temp = head;
        Node* tail = head->prev; // Get last node
        head = head->next;
        head->prev = tail;
        tail->next = head;
        delete temp;
    }
    
    void deleteAtEnd() {
        if (head == NULL) {
            return;
        }

        if (head->next == head) { // Only one node present
            delete head;
            head = NULL;
            return;
        }

        Node* tail = head->prev; // Get last node
        Node* secondLast = tail->prev;
        secondLast->next = head;
        head->prev = secondLast;
        delete tail;
    }

    void display() {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }

        Node* temp = head;
        do {
            cout << temp->val << " <-> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(Back to head)" << endl;
    }
};

int main() {
    DoublyCircularLinkedList dcll;
    dcll.insertAtStart(3);
    dcll.insertAtStart(2);
    dcll.insertAtStart(1);
    dcll.display();
    
    dcll.insertAtEnd(4);
    dcll.display();
    
    dcll.deleteAtStart();
    dcll.display();
    
    dcll.deleteAtEnd();
    dcll.display();
    
    return 0;
}

