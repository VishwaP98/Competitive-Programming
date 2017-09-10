#include <iostream>

struct node{
	int data;
	node* next;
};

void reverse_linked_list(node ** head){
	node * pointer = *head;
	if(pointer != NULL){
		node * temp = pointer->next;
		pointer->next = NULL;
		node * temp2 = temp;

		while(temp != NULL){
			temp2 = temp->next;
			temp->next = pointer;
			pointer = temp;
			temp = temp2;
		}		
		*head = pointer;
	}
}
void printList(node* head){
	if(head == NULL){
		std::cout << " Sorry can't print an empty linked list" << std::endl;
	}
	while(head!=NULL){
		std::cout << " " << head->data;
		head = head->next;
	}
}

void push(node** head, int data){
	node * new_node = new node();
	new_node->data = data;
	new_node->next = *head;
	*head = new_node;
}

int main(){
	node * start = NULL;
	push(&start, 7);
    push(&start, 5);
    push(&start, 4);
    push(&start, 3);
    push(&start, 2);
    printList(start);
    std::cout << std::endl;

    reverse_linked_list(&start);
    
	printList(start);
	return 0;
}
