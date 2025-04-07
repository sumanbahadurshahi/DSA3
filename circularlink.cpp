#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    
    Node(int data) {
        val = dat
		a;
        next = NULL;
    }
};

class CircularLinkedList {
public:
    Node* head;
    
    CircularLinkedList() {
        head = NULL;
    }
    
    void insertAtStart(int val) {
        Node* new_node = new Node(val);
        if (head == NULL) {
            head = new_node;
            new_node->next = head;
            return;
        }

        Node* tail = head;
        while (tail->next != head) {
            tail = tail->next;
        }

        tail->next = new_node;
        new_node->next = head;
        head = new_node;
    }
    
    void insertAtEnd(int val) {  // Function name changed for consistency
        Node* new_node = new Node(val);
        if (head == NULL) {
            head = new_node;
            new_node->next = head;
            return;
        }
        Node* tail = head;
        while (tail->next != head) {
            tail = tail->next;
        }
        // Tail is pointing to the last node
        tail->next = new_node;
        new_node->next = head;
    }
    
    
void deleteatstart(){
	if(head==NULL){
		return;
	}
	Node*temp=head;
	Node*tail=head;
	while(tail->next!=head){
		tail=tail->next;
	}
	head=head->next;
	tail->next=head;
	delete temp; 
}
void deleteatend(){
	if(head==NULL){
		return;
	}
	Node*tail=head;
	while(tail->next->next!=head){
		tail=tail->next;
	}
	//tail is pointing to the second last node
	Node*temp=tail->next;
	tail->next=head;
	delete temp;
}



    void display() {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }

        Node* temp = head;
        do {
            cout << temp->val << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(Back to head)" << endl;
    }
};

int main() {
    CircularLinkedList cll;
    cll.insertAtStart(3);
    cll.insertAtStart(2);
    cll.insertAtStart(1);
    cll.display();
    cll.insertAtEnd(4);  // Insert 4 instead of 3 to avoid confusion
    cll.display();
    cll.deleteatstart();
    cll.display();
    cll.deleteatend();
    cll.display();
    
    return 0;
}

