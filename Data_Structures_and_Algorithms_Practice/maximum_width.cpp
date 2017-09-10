#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sstream>
#include <queue>
#include <vector>

struct node{
	int data;
	node * left;
	node * right;
};

int max_width(node * root){
	int size = 1;
	int max = 1;
	std::queue<node *> queue;
	queue.push(root);
	while(!queue.empty()){
		for(int x = 0; x < size; x++){
			node * temp = queue.front();
			queue.pop();
			if(temp->right != NULL){
				queue.push(temp->right);
			}
			if(temp->left != NULL){
				queue.push(temp->left);
			}
		}
		size = queue.size();
		if(size > max){
			max = size;
		}
	}
	return max;
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
	 root->left->left = new node();
	 root->left->left->data = 3;
	 root->right->left = new node();
	 root->right->left->data = 7;
	 root->right->right = new node();
	 root->right->right->data = 7;
	 printf("%d\n",max_width(root));

	 return 0;
}
