#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <sstream>
#include <stack>
#include <vector>

class my_queue{
	std::stack<int> first;
	std::stack<int> second;
	int capacity;
public:
	my_queue(int cap);
	void push(int num);
	int pop();
	int peek();
};

my_queue::my_queue(int cap){
	capacity = cap;
}

void my_queue::push(int num){
	if(first.size() != capacity){
		first.push(num);
	}
	// otherwise throw exception
}

int my_queue::pop(){
	if(second.size() == 0){
		if(first.size() == 0){
			// Throw exception
		}
		// otherwise
		int val = peek();
		second.pop();
		return val;
	}
	int val = second.top();
	second.pop();
	return val;
}

int my_queue::peek(){
	if(second.size() == 0){
		if(first.size() == 0){// Throw exception}
		}
		while(first.size() != 0){
			second.push(first.top());
			first.pop();
		}
		int val = second.top();
		return val;
	}
	int val = second.top();
	return val;
}

int main(){
	 my_queue queue(5);
	 queue.push(5);
	 queue.push(6);
	 queue.push(3);
	 queue.push(7);
	 printf("The first val is %d\n",queue.pop());
	 printf("The second val is %d\n",queue.peek());
	 return 0;
}
