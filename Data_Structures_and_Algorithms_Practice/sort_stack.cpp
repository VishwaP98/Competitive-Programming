#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sstream>
#include <stack>
#include <vector>

void sort_stack(std::stack<int>& stk){
	std::stack<int> temp;
	if(stk.empty()){
		// Throw exception
		exit(1);
	}
	int small = stk.top();
	stk.pop();
	while(!stk.empty()){
		int compare = stk.top();
		stk.pop();
		int val;
		small >= compare ? val = small : val = compare;
		if(small == val){small = compare;}
		while(!temp.empty() && temp.top() < val){
			stk.push(temp.top());
			temp.pop();
		}
		temp.push(val);
	}
	while(!stk.empty()){
			temp.push(stk.top());
			stk.pop();
	}
	temp.push(small);
	stk = temp;
}

int main(){
	 std::stack<int> stack;
	 stack.push(5);
	 stack.push(6);
	 stack.push(3);
	 stack.push(7);
	 sort_stack(stack);
	 printf("The value at top is %d\n",stack.top());
	 stack.pop();
	 printf("The value at top is %d\n",stack.top());
	stack.pop();
	printf("The value at top is %d\n",stack.top());
	stack.pop();
	printf("The value at top is %d\n",stack.top());
	stack.pop();

	 return 0;
}
