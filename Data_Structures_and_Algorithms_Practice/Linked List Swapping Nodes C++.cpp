#include <iostream>

struct node{
	int data;
	node* next;
};

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

void swap_nodes(node** start, int data1, int data2){
	node* check = NULL; 
	check = *start;
	node* check2 = NULL;
	check2 = *start;
	node* pre1 = NULL;
	node* pre2 = NULL;
	
	while(check != NULL && check->data != data1){
		pre1 = check;
		check = check->next;
	}
	
	while(check2 != NULL && check2->data != data2){
		pre2 = check2;
		check2 = check2->next;
	}

	// First case is to check whether both of the pointers are found
	if(check != NULL && check2 != NULL){
		// Second case is to check whether any of the pointers is the head of the linked list
		if(pre1 != NULL && pre2 != NULL){
			
			// If both nodes are not the last ones
			if(check->next !=NULL && check2->next != NULL){
				
				// Pointers not right beside each other
				if(check->next != check2 && check2->next != check){
					std::cout << " He;;" << std::endl;
					node* temp = NULL;
					node* temp2 = NULL;
					temp = check;
					temp2 = check2->next;
					pre1->next = check2;
					check2->next = temp->next;
					pre2->next = temp;
					temp->next = temp2;
				}
				// Otherwise, must handle it specially
				else{
					std::cout << "Hey" << std::endl;
					// If the first pointer is ahead in the linked list
					if(check->next == check2){
						pre1->next = check2;
						node* temp = check2->next;
						check2->next = check;
						check->next = temp;
					}
					// Otherwise, must handle it specially
					else if(check2->next == check){
						pre2->next = check;
						node* temp = check->next;
						check->next = check2;
						check2->next = temp;
					}
				}
			}
			// Otherwise must handle it specially
			else{
				if(check->next == NULL){
					pre1->next = check2;
					check2->next->next = check;
				}
				else{
					pre2->next = check;
					check->next->next = check2;
				}
			}
		}
		else{
			node* temp = NULL;
			node* temp2 = NULL;
			if(pre1 == NULL){
				temp = check->next;
				pre2->next = check;
				check->next = check2->next;
				check2->next = temp;
				*start = check2;
			}
			else if (pre2 == NULL){
				temp = check;
				pre1->next = check2;
				check2->next = check->next;
				check->next = temp;
				*start = check;
			}
			else if (pre1 == NULL && check2->next == NULL){
				check2->next = check->next;
				pre2->next = check;
				*start = check2;
			}
			else if (pre2 == NULL && check->next == NULL){
				check->next = check2->next;
				pre1->next = check2;
				*start = check;
			}
		}
		
	
	}
}

/* Function to get the middle of the linked list*/
void printMiddle(node *head)
{
    struct node *slow_ptr = head;
    struct node *fast_ptr = head;
 
    if (head!=NULL)
    {
        while (fast_ptr != NULL && fast_ptr->next != NULL)
        {
            fast_ptr = fast_ptr->next->next;
            slow_ptr = slow_ptr->next;
        }
        printf("The middle element is [%d]\n\n", slow_ptr->data);
    }
}

void delete_whole_linked_list(node ** head){
	node * pointer = *head;
	while(*head != NULL){
		node * temp = pointer->next;
		pointer->next = NULL;
		*head = temp;
	}
}

int main(){
	node * start = NULL;
	/* The constructed linked list is:
     1->2->3->4->5->6->7 */
    //push(&start, 7);
    push(&start, 6);
    push(&start, 5);
    push(&start, 4);
    push(&start, 3);
    push(&start, 2);
    push(&start, 1);
 
    printf("\n Linked list before calling swapNodes() ");
    printList(start);
 
//    swap_nodes(&start, 3, 5);
//    printf("\n Linked list after calling swapNodes() ");
//    printList(start);
    
//    swap_nodes(&start, 3, 4);
//    printf("\n Linked list after calling swapNodes() ");
//    printList(start);
    
//    swap_nodes(&start, 1, 7);
//    printf("\n Linked list after calling swapNodes() ");
//    printList(start);
    
    swap_nodes(&start, 4, 4);
    printf("\n Linked list after calling swapNodes() ");
    printList(start);
    std::cout << std::endl;
    printMiddle(start);
    std::cout << std::endl;
    delete_whole_linked_list(&start);
    printList(start);
 
    return 0;
}
