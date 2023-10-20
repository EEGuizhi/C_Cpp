#include <iostream>
#include <stack>

using namespace std;

class Node{
	public:
		int data;
		Node *next;
};

void push(Node** head_ref, int new_data) {
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

void append(Node** head_ref, int new_data) {
	Node* new_node = new Node();
	Node *last = *head_ref;
	new_node->data = new_data;
	new_node->next = NULL;
	
	if(*head_ref == NULL) {
		*head_ref = new_node;
		return;
	}
	while(last->next != NULL) {
		last = last->next;
	}
	last->next = new_node;
	return;
}

void printList(Node *node) {
	while(node != NULL) {
		cout << " " << node->data;
		node = node->next;
	}
}

// insert after
void insert_after(Node* head, int new_data) {
	Node* new_node = new Node();
	new_node->data = new_data;

	new_node->next = head->next;
	head->next = new_node;
	// push(&(*head_ref)->next, new_data);
}

int main() {
	Node* head = NULL;
	
	//linked list : 5->NULL
	append(&head, 5);
	push(&head, 3);
	append(&head, 6);
	push(&head, 1);
	insert_after(head, 2);
	insert_after(head->next->next, 4);
	
	cout << "Output Linked list is: ";
	printList(head);
	
	return 0;	
}
