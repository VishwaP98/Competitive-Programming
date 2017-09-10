#include <stdio.h>

struct tree_node {
	int data;
	tree_node * left;
	tree_node * right;
};

void insert(tree_node * tree_head, int value){
	tree_node * parent = NULL;
	tree_node * temp = tree_head;
	while(temp != NULL){
		parent = temp;
		if(temp->data > value){
			temp = temp->left;
		}
		else{
			temp = temp->right;
		}
	}
	// Once we reach a leaf node then we can create the new node
	if(parent->data > value){
		parent->left = new tree_node();
		parent->left->data = value;
	}
	else{
		parent->right = new tree_node();
		parent->right->data = value;
	}
}

void preorder(tree_node * head){
	if(head != NULL){
		printf(" %d",head->data);
		preorder(head->left);
		preorder(head->right);
	}

}

void inorder(tree_node * head){
	if(head != NULL){
		inorder(head->left);
		printf(" %d",head->data);
		inorder(head->right);
	}
}

void postorder(tree_node * head){
	if(head != NULL){
		postorder(head->left);
		postorder(head->right);
		printf(" %d",head->data);
	}
}


int main(){
	int a = 0;
	scanf("%d", &a);
	tree_node * head = new tree_node();
	for(int x = 0; x < a; x++){
		int b = 0;
		scanf("%d",&b);
		if(x == 0){
			head->data = b;
		}
		else{
			insert(head, b);
		}
	}
	printf("Pre order :");
	preorder(head);
	printf("\nIn order  :");
	inorder(head);
	printf("\nPost order:");
	postorder(head);
	return 0;
}
