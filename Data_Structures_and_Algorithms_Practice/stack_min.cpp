#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <sstream>
#include <algorithm>
#include <vector>

class stack_min{
	std::vector<int> main;
	std::vector<int> min;
public:
	stack_min();
	void push(int num);
	int pop();
	int getMin();
	bool is_empty(){return main.size() == 0;}
};

stack_min::stack_min(){
	printf("Here in constructor\n");
}
void stack_min::push(int num){
	main.push_back(num);
	if(min.size() == 0 || min.back() > num){
		min.push_back(num);
	}
}

int stack_min::pop(){
	if(min.back() >= main.back()){
		min.pop_back();
	}
	int val = main.back();
	main.pop_back();
	return val;
}

int stack_min::getMin(){
	if(min.size() == 0){
		return -1;
	}
	return min.back();
}

int main(){
	 stack_min stack;
	 stack.push(5);
	 printf("%d\n",stack.getMin());
	 stack.push(6);
	 stack.push(3);
	 stack.push(7);
	 printf("%d\n",stack.getMin());
	 printf("%d\n",stack.pop());
	 printf("%d\n",stack.getMin());
	 stack.pop();
	 printf("%d\n",stack.getMin());
	 return 0;
}
