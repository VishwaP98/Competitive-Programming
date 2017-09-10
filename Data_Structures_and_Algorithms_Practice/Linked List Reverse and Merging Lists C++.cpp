#include <iostream>

struct node{
	int data;
	node* next;
};

void reverse_linked_list(node ** head){
	node * pointer = *head;
	if(pointer != NULL){
		node * temp = pointer;
		node * prev = NULL;

		while(temp != NULL){
			temp = pointer->next;
			pointer->next = prev;
			prev = pointer;
			pointer = temp;
		}		
		*head = prev;
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

node * sorted_merge_list(node * list1, node * list2){
	node * head = NULL;
	node * current = NULL;
	if(list1->data > list2->data){
		head = list2;
		current = head;
		list2 = list2->next;
	}
	else if(list2->data > list1->data){
		head = list1;
		current = head;
		list1 = list1->next;
	}
	else{
		head = list1;
		current = head;
		list2 = list2->next;
	}
	
	while(list1 != NULL && list2 != NULL){
		if(list1->data < list2->data){
			current->next = list1;
			list1 = list1->next;
			current = current->next;
		}
		else if(list1->data > list2->data){
			current->next = list2;
			list2 = list2->next;
			current = current->next;
		}
		else{
			list2 = list2->next;
		}
	}
	if(list1 == NULL && list2 != NULL){
		current->next = list2;
	}
	else{
		current->next = list1;
	}
	
	return head;
		
}

int main(){
	node * start = NULL;
	push(&start, 7);
    push(&start, 5);
    push(&start, 8);
    push(&start, 3);
    push(&start, 2);
    printList(start);
    std::cout << std::endl;

    reverse_linked_list(&start);
    
    printList(start);

    node * a = NULL;
    node * b = NULL;
    node * res = NULL;
    push(&b, 20);
    push(&b, 15);
    push(&b, 12);
    push(&b, 5);
 
    push(&a, 15);
    push(&a, 3);
    push(&a, 2);

  	std::cout << std::endl;

 	std::cout << std::endl;
    std::cout << std::endl;
	/* Remove duplicates from linked list */
    res = sorted_merge_list(a, b);
	printList(res);
	return 0;
}
