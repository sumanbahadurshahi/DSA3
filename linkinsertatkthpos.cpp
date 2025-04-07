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

void insertatposition(Node*&head,int val,int pos){
	if(pos==0){
		insertAtHead(head,val);
		return;
	}
	Node*new_node=new Node(val);
	Node*temp=head;
	int cur_pos=0;
	while(cur_pos!=pos-1){
		temp=temp->next;
		cur_pos++;
	}
	//now temp is pointing to pos-1;
	new_node->next=temp->next;
	temp->next=new_node;
}
 void deleteAtHead(Node*& head) {
    if (head == NULL) { // Check if list is already empty
        return;
    }
    Node* temp = head;
    head = head->next;
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
insertatposition(head, 2,2);
 deleteAtHead(head);
display(head);
    return 0;
}
/*new_node->next = temp->next
This makes new_node (25) point to 30.
temp->next = new_node
This makes temp (20) point to new_node (25).*/

