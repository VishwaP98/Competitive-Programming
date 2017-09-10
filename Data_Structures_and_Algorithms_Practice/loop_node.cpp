#include <stdio.h>
#include <string>
#include <math.h>
#include <stdlib.h>

struct node{
	int num;
	node * next;
};

// O(n) Time Complexity and O(1) space complexity
node * loop_node(node * head){
	node * slow = head;
	node * fast = head;
	while(fast != NULL && fast->next != NULL){
		fast = fast->next;
		fast = fast->next;
		slow = slow->next;
		if(fast == slow){
			break;
		}
	}
	if(fast == NULL || fast->next == NULL){
		return NULL;
	}

	node * head_pt = head;
	while(head_pt != fast){
		head_pt = head_pt->next;
		fast = fast->next;
	}
	return head_pt;
}

int main(){
	node * head = new node();
	// make the test case - just have to make a loop linked list
	return 0;
}
