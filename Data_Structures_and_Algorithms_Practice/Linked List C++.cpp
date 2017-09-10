#include <iostream>
using namespace std;

struct node{
	int data;
	node* next;
};


int main(){
	node* root;
	root = new node;
	root->data = 6;
	root->next = 0; // Root now points to None
	node* curr = new node;
	curr = root;
	if(curr != 0){
		while(curr->next != 0){
			curr = curr->next;
		}
	}
	for(int x=0;x<10;x++){
		curr->next = new node;
		curr = curr->next;
		curr->data = 7 + x;
	}
	curr->next = 0;
	
	
	// Now let's delete the second last node from the linked list
	node* prev = new node;
	curr = root;
	node* second_last = curr->next;

	while(second_last->next != 0){
		prev = curr;
		curr = curr->next;
		second_last = second_last->next;
	}
	prev->next = second_last;
	second_last->next = 0;
	
	curr = root;
	while(curr != 0){
		cout << curr->data << " Data " << endl;
		curr = curr->next;
	}
	return 0;
}
