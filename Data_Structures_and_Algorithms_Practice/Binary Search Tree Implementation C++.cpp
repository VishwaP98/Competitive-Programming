#include <iostream>
#include <stdio.h>
#include <stdlib.h>

struct binnode{
	int data;
	binnode * left;
	binnode * right;
};

class bst{
	binnode * root;
public:

	bst(){
		root = NULL;
	}
	bst(binnode * root1){
		root = root1;
	}
	void insert(binnode * new_node); // Done
	void delete_tree();					 // Still to Do
	bool search(binnode * find_node); // Done
	int find_min();
	int find_max();
	~bst(){};
};


void bst::insert(binnode * new_node){
	binnode * current_node = root;
	binnode * parent = NULL;
	printf("B1\n");
	while(current_node != NULL){
		printf("B12 %d \n", current_node->data);
		parent = current_node;

		if(new_node->data < current_node->data){
			current_node = current_node->left;
		}
		else{
			current_node = current_node->right;
		}
	}
	printf("B13");

	if(new_node->data < parent->data){
		parent->left = new_node;
	}
	else{
		parent->right = new_node;
	}
	printf("B14");

}

// Delete to be done after learning how to implement the delete function

bool bst::search(binnode * find_node){
	bool found = false;
	binnode * current = root;
	while(current->data != find_node->data or current == NULL){
		if(find_node->data < current->data){
			current = current->left;
		}
		else{
			current = current->right;
		}
	}
	
	if(current != NULL){
		found = true;
	}
	
	return found;
	
}

int bst::find_min(){
	int min = 0;
	binnode * current = root;
	while(current->left != NULL){
		current = current->left;
	}
	min = current->data;
	return min;
}

int bst::find_max(){
	int max = 0;
	binnode * current = root;
	while(current->right != NULL){
		current = current->right;
	}
	max = current->data;
	return max;
}

int main(){
	printf("Hi\n");
	binnode * root = new binnode();
	printf("Hi1\n");
	root->data = 5;
	bst binarysearch (root);
	printf("Hi2\n");
	binnode * inst = new binnode();
	inst->data = 6;
	printf("Hi5\n");
	binarysearch.insert(inst);
	printf("Hi4\n");
	int max = binarysearch.find_max();
	printf("Max : %d\n",max);
	int min = binarysearch.find_min();
	printf("Min : %d\n",min);
	
	return 0;

}
