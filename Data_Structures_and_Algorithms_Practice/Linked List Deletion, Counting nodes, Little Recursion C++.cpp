#include <iostream>

struct node{
	int data;
	node* next;
};

void printList(node* head){
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

void delete1(node** head, int data){
	node* pointer = *head;
	if(pointer != NULL && pointer->data == data){
		*head = pointer->next;
	}
	else{
		node* prev = new node();
		while(pointer != NULL && pointer->data != data){
			prev = pointer;
			pointer = pointer->next;
		}
		prev->next = pointer->next;
		pointer->next = NULL;
		
	}
}

void delete_pos(node** head, int pos){
	int counter = 0;
	node * pointer = *head;
	node * prev = NULL;
	if(pointer != NULL && pos == 0){
		*head = pointer->next;
		pointer->next = NULL;		
	}
	else{
		while(counter != pos){
			counter++;
			prev = pointer;
			pointer = pointer->next;
		}
		prev->next = pointer->next;
		pointer->next = NULL;
	}
}

int getcount(node** head){
	node * pointer = new node();
	pointer = *head;
	int count = 0;
	while(pointer != NULL){
		count++;
		pointer = pointer->next;
	}
	return count;
}

int recursivecount(node** head){
	node * pointer = new node();
	pointer = *head;
	int count = 0;
	if(pointer == NULL){
		return 0;
	}
	else if(pointer->next == NULL){
		return 1;
	}
	else{
		count = 1 + recursivecount(&(pointer->next));
	}
	return count;
}
int main(){
	node * head = NULL;
	
	push(&head, 7);
    push(&head, 1);
    push(&head, 3);
    push(&head, 2);
 
    printList(head);
    delete1(&head, 1);
    std::cout << std::endl;
    
    push(&head, 10);
    push(&head, 15);
    delete_pos(&head, 0); // Deletes node at position in linked list
    printList(head); // Prints all the nodes in a Linked List
    std::cout << std::endl;
    std::cout << getcount(&head) << "Count Iteratively " << std::endl; // Counts the number of elements in a Linked List iteratively
    std::cout << recursivecount(&head) << "Count Recursively " << std::endl; // Counts the number of elements in a Linked List recursively
    return 0;
	
}
