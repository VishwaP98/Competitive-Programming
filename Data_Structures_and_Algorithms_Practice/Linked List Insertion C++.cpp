#include <iostream>

using namespace std;

struct node{
	int data;
	struct node* next;
};

void append(node** head, int data){
	node * new_node = new node();
	node * pointer = *head;
	new_node->data = data;
	new_node->next = NULL;
	if(*head == NULL){
		*head = new_node;
	}
	else{
		while(pointer->next != NULL){
			pointer = pointer->next;
		}
		pointer->next = new_node;
	}
}

void push(node** head, int data){
	node * new_node = new node();
	new_node->data = data;
	new_node->next = *head;
	*head = new_node;
}

void printList(node* head){
	while(head!=NULL){
		cout << " " << head->data;
		head = head->next;
	}
}

void insertAfter(node* find, int data){
	node* new_node = new node();
	new_node->data = data;
	new_node->next = find->next;
	find->next = new_node;
}


int main(){
	node *head = NULL;
	append(&head, 6);
	append(&head, 7);
	push(&head,1);
	insertAfter(head->next->next, 8);
	
	printf("\n Created Linked list is:");
	printList(head);
	return 0;	
}
