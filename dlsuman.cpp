#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;

    Node(int data) {
        val = data;
        prev = NULL;
        next = NULL;
    }
};

class Doublylinklist {
public:
    Node* head;
    Node* tail;

    Doublylinklist() {
        head = NULL;
        tail = NULL;
    }

    void insertatstart(int val) {
        Node* new_node = new Node(val);
        if (head == NULL) {
            head = new_node;
            tail = new_node;
            return;
        }
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
    
    void insertatend(int val) {
        Node* new_node = new Node(val);
        if (tail == NULL) {
            head = new_node;
            tail = new_node;
            return;
        }
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    } 
   
    void insertatposition(int val, int k) {
        if (k == 1) { // Insert at start
            insertatstart(val);
            return;
        }
        
        Node* temp = head;
        int count = 1;

        while (temp != NULL && count < k - 1) { // Traverse to k-1 position
            temp = temp->next;
            count++;
        }

        if (temp == NULL || temp->next == NULL) { // Insert at end if position exceeds the list
            insertatend(val);
            return;
        }

        Node* new_node = new Node(val);
        new_node->next = temp->next;
        temp->next->prev = new_node;
        temp->next = new_node;
        new_node->prev = temp;
    }
    
    void deleteatstart() {
        if (head == NULL) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head == NULL) { // If the list becomes empty, update tail
            tail = NULL;
        } else {
            head->prev = NULL;
        }
        delete temp;
    }
    
    void deleteatend() {
        if (head == NULL) { // If list is empty, do nothing
            return;
        }
        Node* temp = tail;
        tail = tail->prev;
        if (tail == NULL) { // If list becomes empty after deletion
            head = NULL;
        } else {
            tail->next = NULL;
        }
        delete temp;
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->val;
            if (temp->next != NULL) cout << " <-> ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Doublylinklist dll;
    dll.insertatstart(1);
      dll.insertatstart(7);
     dll.insertatstart(5);
    dll.insertatstart(2);
    dll.display();
    dll.insertatend(3);
    dll.display();
    dll.insertatposition(4, 3);
    dll.display();
    
    dll.deleteatstart();
    dll.display(); // Checking if the first element is deleted

    dll.deleteatend();
    dll.display(); // Checking if the last element is deleted

    return 0;
}

