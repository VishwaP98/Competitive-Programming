#include <iostream>

struct node{
	int data;
	node* next;
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

void print(node** head){
	node* newnode = *head;
	while(newnode != NULL){
		std::cout << newnode->data << " " << std::endl;
		newnode = newnode->next;
	}
	
}

void remove_duplicate(node** head){
	node* curr = *head;
	while(curr->next != NULL){
		node* curr_next = curr->next;
		if(curr->data == curr_next->data){
			curr->next = curr_next->next;
			delete curr_next;
		}
		else{
			curr = curr->next;			
		}
	}
}

void remove_duplicates_from_unsorted_list(node**head){
	
}

int main(){
	
	node* head = new node();
	head->data = 5;
	append(&head, 5);
	append(&head, 5);
	append(&head, 7);
	append(&head, 7);
	remove_duplicate(&head);
	print(&head);	
	
	
	
	return 0;
}
