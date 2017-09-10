#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sstream>
#include <stack>
#include <vector>

struct node{
	int data;
	node * left;
	node * right;
};

int vertical_sum(node * root, int sum, int offset){
	int sum1,sum2,new_sum = 0;
	if(root == NULL){
		return sum;
	}
	else{
		new_sum = sum;
		if(offset == 0){
			new_sum += root->data;
		}

		sum1 = vertical_sum(root->left,new_sum,offset - 1);
		sum2 = vertical_sum(root->right,new_sum, offset + 1);

	}
	return sum1 + sum2 - new_sum;
}

int main(){
	 node * root = new node();
	 root->data = 5;
	 root->left = new node();
	 root->left->data = 4;
	 root->right = new node();
	 root->right->data = 6;
	 root->left->right = new node();
	 root->left->right->data = 3;
	 root->right->left = new node();
	 root->right->left->data = 7;
	 printf("%d\n",vertical_sum(root,0,0));

	 return 0;
}
